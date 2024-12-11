#include <iostream>
#include <memory>
#include <libcamera/libcamera.h>
#include <opencv2/opencv.hpp>  // OpenCV for image handling

#include "imageProcess.cpp"

#define TIMEOUT_SEC 3

using namespace libcamera;

std::shared_ptr<Camera> camera;

static void requestComplete(Request *request)
{
    if (request->status() == Request::RequestCancelled)
        return;

    const Request::BufferMap &buffers = request->buffers();
    for (auto &bufferPair : buffers)
    {
        FrameBuffer *buffer = bufferPair.second;
        const FrameMetadata &metadata = buffer->metadata();

        std::cout << "Captured frame: " << std::endl;
        std::cout << "Sequence: " << metadata.sequence
                  << ", Timestamp: " << metadata.timestamp
                  << ", Bytes used: " << metadata.planes()[0].bytesused << std::endl;

        // Assuming the first plane contains the image data
        uint8_t *data = static_cast<uint8_t *>(buffer->planes()[0].data());
        size_t width = metadata.planes()[0].size.width();
        size_t height = metadata.planes()[0].size.height();

        // Create an OpenCV Mat from the raw data
        cv::Mat image(height, width, CV_8UC3, data);

        // Save the image to disk
        cv::imwrite("captured_image.jpg", image);
    }

    // Reuse the request for future captures
    request->reuse(Request::ReuseBuffers);
    camera->queueRequest(request);
}

cv::Mat takePicture()
{
    // Initialize CameraManager and start it
    std::unique_ptr<CameraManager> cm = std::make_unique<CameraManager>();
    cm->start();

    // Ensure there is a camera available
    if (cm->cameras().empty()) {
        std::cerr << "No cameras found!" << std::endl;
        return cv::Mat();
    }

    // Use the first available camera
    camera = cm->get(cm->cameras()[0]->id());
    camera->acquire();

    // Create and validate configuration for the camera
    std::unique_ptr<CameraConfiguration> config = camera->generateConfiguration({StreamRole::Viewfinder});
    config->validate();
    camera->configure(config.get());

    // Create a FrameBufferAllocator to manage buffers
    FrameBufferAllocator allocator(camera.get());
    for (StreamConfiguration &cfg : *config)
    {
        int ret = allocator.allocate(cfg.stream());
        if (ret < 0) {
            std::cerr << "Buffer allocation failed!" << std::endl;
            return cv::Mat();
        }
    }

    // Prepare a request to capture an image
    Stream *stream = config->at(0).stream();
    std::unique_ptr<Request> request = camera->createRequest();
    if (!request)
    {
        std::cerr << "Unable to create request!" << std::endl;
        return cv::Mat();
    }

    // Assign buffer to the request
    const std::unique_ptr<FrameBuffer> &buffer = allocator.buffers(stream).at(0);
    int ret = request->addBuffer(stream, buffer.get());
    if (ret < 0)
    {
        std::cerr << "Failed to add buffer to request!" << std::endl;
        return cv::Mat();
    }

    // Set the request completed callback
    camera->requestCompleted.connect(requestComplete);

    // Start the camera and queue the request
    camera->start();
    camera->queueRequest(request.get());

    // Wait for the capture to complete (simple timeout handling)
    std::this_thread::sleep_for(std::chrono::seconds(TIMEOUT_SEC));

    // Stop the camera and clean up
    camera->stop();
    allocator.free(stream);
    camera->release();
    cm->stop();

    return cv::imread("captured_image.jpg");
}
