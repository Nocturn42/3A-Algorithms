import cv2

# 讀取影像
image = cv2.imread("image.jpg")

# 創建一個窗口，用來顯示影像
cv2.namedWindow("image")
cv2.imshow("image", image)

# 創建一個自動對焦器
detector = cv2.SimpleBlobDetector_create()

# 使用自動對焦器來對影像進行對焦
keypoints = detector.detect(image)

# 在影像中繪製對焦點
output = cv2.drawKeypoints(image, keypoints, None)

# 顯示對焦後的影像
cv2.namedWindow("output")
cv2.imshow("output", output)

# 等待按鍵
cv2.waitKey()

#這個範例中，使用了OpenCV-Python模塊中的SimpleBlobDetector_create函數來創建一個自動對焦器。然後，通過調用自動對焦器的detect方法，對影像進行對焦。最後，使用drawKeypoints函數將對焦點繪製到影像中，並顯示結果。
