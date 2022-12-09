#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {
  // 讀取影像
  Mat image = imread("image.jpg");

  // 創建一個窗口，用來顯示影像
  namedWindow("image");
  imshow("image", image);

  // 創建一個自動白平衡器
  // 在這個例子中，我們使用了白平衡模式為自動白平衡
  // 具體的，自動白平衡器會根據影像中的色彩信息來自動調整影像的白平衡
  // 最終，自動白平衡器會將影像中的所有顏色調整到相同的亮度和飽和度，以便確保影像的色彩平衡
  Ptr<SimpleWB> balancer = createSimpleWB();
  balancer->setWhiteBalance(WB_SIMPLE);

  // 使用自動白平衡器來對影像進行白平衡
  Mat image2;
  balancer->balanceWhite(image, image2);

  // 創建一個窗口，用來顯示白平衡後的影像
  namedWindow("image2");
  imshow("image2", image2);

  // 等待按鍵
  waitKey();

  return 0;
}
