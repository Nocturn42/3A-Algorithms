import cv2

# 讀取影像
image = cv2.imread("image.jpg")

# 創建一個窗口，用來顯示影像
cv2.namedWindow("image")
cv2.imshow("image", image)

# 創建一個自動白平衡器
# 在這個例子中，我們使用了白平衡模式為自動白平衡
# 具體的，自動白平衡器會根據影像中的色彩信息來自動調整影像的白平衡
# 最終，自動白平衡器會將影像中的所有顏色調整到相同的亮度和飽和度，以便確保影像的色彩平衡
balancer = cv2.createWB()
balancer.setWBPoint(cv2.WB_AUTO)

# 使用自動白平衡器來對影像進行白平衡
image = balancer.balanceWhite(image)

# 創建一個窗口，用來顯示白平衡後的影像
cv2.namedWindow("image")
cv2.imshow("image", image)

# 等待按鍵
cv2.waitKey()
