#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

int main(int argc, char** argv)
{
    // 初始化攝像頭並捕捉視頻流
    cv::VideoCapture cap;
    cap.open(0);  // 打开第一個可用攝像頭

    if (!cap.isOpened())
    {
        // 如果攝像頭無法打開，輸出錯誤信息並退出程式
        std::cerr << "ERROR: Could not open camera" << std::endl;
        return -1;
    }

    // 在無限循環中捕捉攝像頭視頻流，並對影像進行處理
    while (true)
    {
        cv::Mat frame;
        cap >> frame;  // 捕捉新的影像

        if (frame.empty())
        {
            // 如果影像為空，輸出錯誤信息並退出程式
            std::cerr << "ERROR: Could not grab frame from camera" << std::endl;
            return -1;
        }

        // 在這裡對影像進行處理，例如自動曝光

        cv::imshow("Frame", frame);
        if (cv::waitKey(1) == 27)
        {
            // 按下ESC鍵，退出程式
            break;
        }
    }

    // 在程式結束時關閉攝像頭並釋放資源
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
