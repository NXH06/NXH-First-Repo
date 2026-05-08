from PIL import Image
import numpy as np

def sobel(arr: np.ndarray):
    radius = 1 # to simplify things, each region has only 9 pixels.
    output1 = output2 = arr.copy() # derivative filters require calculation on original pixels
    for row in range(radius, arr.shape[0] - radius):
        for col in range(radius, arr.shape[1] - radius):
            region = np.array(arr[row-radius:row+radius+1, col-radius:col+radius+1])
            kernel1 = np.array(
            [[-1, -2, -1],
            [0, 0, 0],
            [1, 2, 1]])
            kernel2 = np.array(
            [[-1, 0, 1],
            [-2, 0, 2],
            [-1, 0, 1]])
            output1[row][col] = np.sum(region * kernel1)
            output2[row][col] = np.sum(region * kernel2)
            output = output1 + output2
    output = np.clip(output2, 0, 255) # filter contains negative values, so output must be clipped into range
    output = np.subtract(arr, output)
    return Image.fromarray(output)

def main():
    img = Image.open("cat.jpg")
    arr = np.array(img)
    img_processed = sobel(arr)
    img_processed.save("cat_sobel.jpg")

main()
