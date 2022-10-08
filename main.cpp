#include "console.h"

// mkdir build && cd build && cmake .. && cmake --build . --config Release

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

auto main() -> int
{
    std::string image_path = "PE_Image.jpg";
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);

    if (img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }

    cv::imshow("Display window", img);

    int k = cv::waitKey(0); // Wait for a keystroke in the window
    if (k == 's')
    {
        cv::imwrite("starry_night.png", img);
    }

    Console app;
    return app.run();
}
