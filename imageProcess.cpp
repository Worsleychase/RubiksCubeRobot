// imageProcess.cpp

#include <opencv2/opencv.hpp>

std::string returnFaceColors() {
    cv::Mat image = cv::imread("testInput.png");
    if (image.empty()) {
        std::cerr << "Error: Unable to load image!" << std::endl;
        return "Error";
    }
    cv::Mat hsvImage;
    cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);

    std::vector<std::pair<cv::Scalar, cv::Scalar>> colorRanges = {
        {cv::Scalar(0, 50, 50), cv::Scalar(10, 255, 255)},      // Red 
        {cv::Scalar(170, 50, 50), cv::Scalar(180, 255, 255)},   // Also Red 
        
        {cv::Scalar(35, 50, 50), cv::Scalar(85, 255, 255)},     // Green
        {cv::Scalar(100, 50, 50), cv::Scalar(140, 255, 255)},   // Blue
        {cv::Scalar(20, 50, 50), cv::Scalar(30, 255, 255)},     // Yellow
        {cv::Scalar(10, 100, 100), cv::Scalar(25, 255, 255)},   // Orange
        {cv::Scalar(0, 0, 200), cv::Scalar(180, 20, 255)}       // White
    };

    std::vector<std::string> colorNames = {"Red", "Red", "Green", "Blue", "Yellow", "Orange", "White"};
    if (colorRanges.size() != colorNames.size()) {
        std::cerr << "Error: Mismatch between color ranges and color names!" << std::endl;
        return "Error";
    }

    // Map color names
    std::vector<char> colorCodes = {'R', 'R', 'G', 'B', 'Y', 'O', 'W'};

    int rows = 3, cols = 3;
    int cellWidth = image.cols / cols;
    int cellHeight = image.rows / rows;
    std::vector<char> cellColors(9, ' ');

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            cv::Rect roi(col * cellWidth, row * cellHeight, cellWidth, cellHeight);
            cv::Mat cellImage = hsvImage(roi);

            int colorIndex = -1;
            int maxColorCount = 0;

            for (size_t i = 0; i < colorRanges.size(); ++i) {
                cv::Mat mask;
                cv::inRange(cellImage, colorRanges[i].first, colorRanges[i].second, mask);

                int colorCount = cv::countNonZero(mask);
                if (colorCount > maxColorCount) {
                    maxColorCount = colorCount;
                    colorIndex = i;
                }
            }

            if (colorIndex >= 0) {
                cellColors[row * cols + col] = colorCodes[colorIndex];
            } else {
                cellColors[row * cols + col] = 'U'; // Unknown color
            }
        }
    }

    std::string result;
    for (char colorCode : cellColors) {
        result += colorCode;
    }

    return result;
}
