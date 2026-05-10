from PIL import Image
import numpy as np

thres = 100

def thresholding(arr: np.ndarray):
    #print(arr.flags)
    for row in range(arr.shape[0]):
        for col in range(arr.shape[1]):
            if arr[row][col] > thres:
                arr[row][col] = 255
            else: 
                arr[row][col] = 0
    return Image.fromarray(arr)

def main():
    img_name = input("Image name: ")
    img = Image.open(f"{img_name}.jpg")
    arr = np.array(img)
    #arr.setflags(write=1)
    #print(arr.flags)
    img_processed = thresholding(arr)
    img_processed.save(f"{img_name}_thres.jpg")

main()
