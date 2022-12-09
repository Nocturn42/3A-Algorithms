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

  // 創建一個自動對焦器
  Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create();

  // 使用自動對焦器來對影像進行對焦
  vector<KeyPoint> keypoints;
  detector->detect(image, keypoints);

  // 在影像中繪製對焦點
  Mat output;
  drawKeypoints(image, keypoints, output);

  // 顯示對焦後的影像
  namedWindow("output");
  imshow("output", output);

  // 等待按鍵
  waitKey();

 //這個範例中，使用了OpenCV中的SimpleBlobDetector類來創建一個自動對焦器。然後，通過調用自動對焦器的detect方法，對影像進行對焦。最後，使用drawKeypoints函數將對焦點繪製到影像中，並顯示結果。

  return 0;
}
