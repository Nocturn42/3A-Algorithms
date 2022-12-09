#include opencv2opencv.hpp
#include iostream

using namespace std;
using namespace cv;

int main()
{
     // 打開攝像頭
    VideoCapture camera(0);
    if (!camera.isOpened())
    {
        cout  Failed to open camera!  endl;
        return -1;
    }

     // 設置視頻尺寸
    camera.set(CAP_PROP_FRAME_WIDTH, 640);
    camera.set(CAP_PROP_FRAME_HEIGHT, 480);

     // 創建視窗
    namedWindow(Camera);

     // 捕獲視頻帧
    Mat frame;
    while (true)
    {
         // 捕獲下一個視頻帧
        camera  frame;

         // 計算畫面中每個像素的平均亮度值
        Scalar mean, stddev;
        meanStdDev(frame, mean, stddev);
        double brightness = mean[0];

         // 根據畫面亮度調整快門速度和光圈大小
        if (brightness  100)
        {
            camera.set(CAP_PROP_EXPOSURE, -5);
            camera.set(CAP_PROP_APERTURE, 5.6);
        }
        else if (brightness  200)
        {
            camera.set(CAP_PROP_EXPOSURE, 0);
            camera.set(CAP_PROP_APERTURE, 4.5);
        }
        else
        {
            camera.set(CAP_PROP_EXPOSURE, 5);
            camera.set(CAP_PROP_APERTURE, 3.5);
        }

         // 顯示視頻帧
        imshow(Camera, frame);
        if (cv::waitKey(1) == 27)
        {
            //  按下ESC鍵，退出程式
            break;
    }

    // 在程式結束時關閉攝像頭並釋放資源
    cap.release();
    cv::destroyAllWindows();

    return 0;
}