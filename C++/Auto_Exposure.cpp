#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
  // Open the default camera
  VideoCapture cap(0);

  if (!cap.isOpened()) {
    cerr << "ERROR: Could not open camera" << endl;
    return 1;
  }

  // Set the camera to auto exposure
  cap.set(CAP_PROP_AUTO_EXPOSURE, 1.0);

  while (true) {
    Mat frame;

    // Read a frame from the camera
    cap >> frame;

    if (frame.empty()) {
      cerr << "ERROR: Could not grab frame from camera" << endl;
      break;
    }

    // Show the frame
    imshow("Camera", frame);

    // Check for user input
    if (waitKey(1) >= 0) {
      break;
    }
  }

  return 0;
}
// This code will open the default camera and set it to auto exposure mode. It will then continuously grab frames from the camera and display them on the screen. When the user presses any key, the program will exit.

// You will need to have the OpenCV library installed on your computer to compile and run this code. You can learn more about how to install OpenCV on the OpenCV website: https://opencv.org/




