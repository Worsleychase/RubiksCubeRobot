#include "imageProcess.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread> // For sleep functionality

bool captureImage() {
    // Construct the libcamera-still command
    std::string command = std::string("libcamera-still --immediate --width 3280 --height 2464 --encoding jpg ")
                          + "-o topFace.jpg"
                          + " --roi 0.125,0.1,0.75,0.75 --nopreview --vflip --hflip"
                          + " > /dev/null 2>&1";  // Redirects stdout and stderr to /dev/null

    int result = std::system(command.c_str());

    // Check if the command executed successfully
    if (result != 0) {
        std::cerr << "Error: libcamera-still command failed with exit code " << result << std::endl;
        return false;
    }

    // Verify the image file exists
    if (std::ifstream("topFace.jpg").fail()) {
        std::cerr << "Error: Image file 'topFace.jpg' not found!" << std::endl;
        return false;
    }

    return true;
}

std::string returnFaceColors() {
    if (!captureImage()) {
        return "Error: Failed to capture image.";
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    cv::Mat image = cv::imread("topFace.jpg", cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Error: Unable to load image!" << std::endl;
        return "Error";
    }

    // Crop 100 pixels from left and right
    int trim_pixels = 300;
    int x = trim_pixels;  // Start 100 pixels in from the left
    int y = 0;  // Keep the top as it is (start from the top)
    
    // Adjust the width to trim 100 pixels from each side
    int width = image.cols - 2 * trim_pixels;  // Remove 100 pixels from each side
    int height = image.rows;  // Keep the full height

    // Ensure the dimensions are valid
    if (width <= 0) {
        std::cerr << "Error: Width is too small after trimming!" << std::endl;
        return "Error";
    }

    // Define the region of interest (ROI) for cropping
    cv::Rect roi(x, y, width, height);
    cv::Mat croppedImage = image(roi);  // Crop the image

    // Save the cropped image back to topFace.jpg to replace the original
    if (!cv::imwrite("topFace.jpg", croppedImage)) {
        std::cerr << "Error: Failed to save the cropped image!" << std::endl;
        return "Error";
    }

    // Now, proceed with color detection using the cropped image (croppedImage)
    cv::Mat hsvImage;
    cv::cvtColor(croppedImage, hsvImage, cv::COLOR_BGR2HSV);

    std::vector<std::pair<cv::Scalar, cv::Scalar>> colorRanges = {
        {cv::Scalar(160, 225, 50), cv::Scalar(179, 255, 255)},   // Red 
        {cv::Scalar(65, 200, 50), cv::Scalar(75, 255, 255)},     // Green
        {cv::Scalar(115, 225, 50), cv::Scalar(120, 255, 255)},   // Blue
        {cv::Scalar(36, 105, 50), cv::Scalar(64, 205, 255)},     // Yellow
        {cv::Scalar(7, 210, 50), cv::Scalar(35, 255, 255)},      // Orange
        {cv::Scalar(105, 30, 50), cv::Scalar(110, 95, 255)}      // White
    };

    std::vector<std::pair<cv::Scalar, cv::Scalar>> colorRangesTL = {
        {cv::Scalar(160, 120, 50), cv::Scalar(179, 255, 255)},    // Red 
        {cv::Scalar(70, 120, 50), cv::Scalar(95, 255, 255)},      // Green
        {cv::Scalar(115, 160, 50), cv::Scalar(120, 255, 255)},   // Blue
        {cv::Scalar(10, 70, 50), cv::Scalar(50, 255, 255)},     // Yellow
        {cv::Scalar(40, 130, 50), cv::Scalar(70, 255, 255)},       // Orange
        {cv::Scalar(105, 20, 50), cv::Scalar(110, 120, 255)}     // White
    };
    
    std::vector<std::string> colorNames = {"Red", "Green", "Blue", "Yellow", "Orange", "White"};
    if (colorRanges.size() != colorNames.size()) {
        std::cerr << "Error: Mismatch between color ranges and color names!" << std::endl;
        return "Error";
    }

    std::vector<char> colorCodes = {'R', 'G', 'B', 'Y', 'O', 'W'};

    int rows = 3, cols = 3;
    int cellWidth = croppedImage.cols / cols;
    int cellHeight = croppedImage.rows / rows;
    std::vector<char> cellColors(9, ' ');

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            cv::Rect roi(col * cellWidth, row * cellHeight, cellWidth, cellHeight);
            cv::Mat cellImage = hsvImage(roi);

            int colorIndex = -1;
            int maxColorCount = 0;

            /*if (row == 0 && col == 0) {
                for (size_t i = 0; i < colorRangesTL.size(); ++i) {
                    cv::Mat mask;
                    cv::inRange(cellImage, colorRangesTL[i].first, colorRangesTL[i].second, mask);

                    int colorCount = cv::countNonZero(mask);
                    if (colorCount > maxColorCount) {
                        maxColorCount = colorCount;
                        colorIndex = i;
                    }
                }
            } else {*/
                for (size_t i = 0; i < colorRanges.size(); ++i) {
                    cv::Mat mask;
                    cv::inRange(cellImage, colorRanges[i].first, colorRanges[i].second, mask);

                    int colorCount = cv::countNonZero(mask);
                    if (colorCount > maxColorCount) {
                        maxColorCount = colorCount;
                        colorIndex = i;
                    }
                }
            //}

            if (colorIndex >= 0) {
                cellColors[row * cols + col] = colorCodes[colorIndex];
            } else {
                cellColors[row * cols + col] = 'U';
            }
        }
    }

    std::string result;
    for (char colorCode : cellColors) {
        result += colorCode;
    }

    std::cout << result << std::endl;
    return result;
}
