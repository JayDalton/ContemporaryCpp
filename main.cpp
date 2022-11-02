#include "console.h"

// mkdir build && cd build && cmake -A Win32 .. && cmake --build . --config Release

// cmake -G "Visual Studio 16 2019" -A Win32 -S \path_to_source\ -B "build32"
// cmake -G "Visual Studio 16 2019" -A x64 -S \path_to_source\ -B "build64"
// cmake --build build32 --config Release
// cmake --build build64 --config Release

#define _WIN32_WINNT 0x0A00
#include <asio.hpp>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

auto main() -> int
{
    print("Contemporary C++\n");

    asio::io_context io;

    asio::steady_timer t(io, asio::chrono::seconds(5));

    t.wait();

    print("timer gone\n");



    std::string image_path = "PE_Image.jpg";
    std::ifstream file(image_path);
    if (file.is_open())
    {
        print("is open\n");
    }
    else 
    {
        print("is not\n");
    }


    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);

    // std::vector<std::int16_t> buffer;
    // std::ifstream file("../wordstop.file");
    // if (file.is_open())
    // {
    //     std::copy(
    //         std::istream_iterator<std::int16_t>{file},
    //         std::istream_iterator<std::int16_t>(),
    //         std::inserter(buffer, buffer.begin())
    //     );
    // }


    if (img.empty())
    {
        print("Could not read the image: {}", image_path);
        return 1;
    }

    print("...\n");

    cv::imshow("Display window", img);

    int k = cv::waitKey(0); // Wait for a keystroke in the window
    // if (k == 's')
    // {
    //     cv::imwrite("starry_night.png", img);
    // }

    return {};
    // Console app;
    // return app.run();
}
