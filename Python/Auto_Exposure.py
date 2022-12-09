import cv2

# 讀取影像
image = cv2.imread("image.jpg")

# 創建一個窗口，用來顯示影像
cv2.namedWindow("image")
cv2.imshow("image", image)

# 設定自動曝光演算法的參數
# 在這個例子中，我們使用了曝光模式為自動曝光，並且指定了自動曝光限制為0.25秒
# 具體的，自動曝光演算法會根據影像中的亮度和細節信息來自動調整曝光時間
# 但是，由於我們指定了自動曝光限制為0.25秒，因此如果曝光時間大於0.25秒，曝光演算法就會被限制在0.25秒
cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_EXPOSURE, cv2.CAP_PROP_AUTO_EXPOSURE)
cap.set(cv2.CAP_PROP_EXPOSURE, 0.25)

# 讀取影像
ret, image = cap.read()

# 創建一個窗口，用來顯示影像
cv2.namedWindow("image")
cv2.imshow("image", image)

# 等待按鍵
cv2.waitKey()
