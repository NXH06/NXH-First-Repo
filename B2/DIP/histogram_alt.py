# phương án của thầy Sơn

import cv2

img = cv2.imread("example.jpg")
print(img.shape)

for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        pixel = img[i][j]
        gray = int((pixel[0] + pixel[1] + pixel[2]) / 3)
        pixel[0] = pixel[1] = pixel[2] = gray

cv2.imwrite("example_gray.jpg", gray)
