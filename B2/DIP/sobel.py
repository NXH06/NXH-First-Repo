from PIL import Image
import numpy as np

def sobel(arr: np.ndarray): # commonly used for edge detection
    radius = 1 # to simplify things, each region has only 9 pixels.
    output_x = arr.copy() # derivative filters require calculation on original pixels
    output_y = arr.copy()
    for row in range(radius, arr.shape[0] - radius):
        for col in range(radius, arr.shape[1] - radius):
            region = np.array(arr[row-radius:row+radius+1, col-radius:col+radius+1])
            kernel_x = np.array(
            [[-1, 0, 1],
            [-2, 0, 2],
            [-1, 0, 1]])
            """kernel_y = np.array(
            [[-1, -2, -1],
            [0, 0, 0],
            [1, 2, 1]])"""
            kernel_y = np.transpose(kernel_x)
            output_x[row][col] = np.sum(region * kernel_x)
            output_y[row][col] = np.sum(region * kernel_y)
    output = np.clip(output_x + output_y, 0, 255)
    output = output.astype(np.uint8) # Image.fromarray takes uint8 array as input
    return Image.fromarray(output)

def main():
    img_name = input("Image name: ")
    img = Image.open(f"{img_name}.jpg")
    arr = np.array(img)
    arr = arr.astype(np.int64)
    img_processed = sobel(arr)
    img_processed.save(f"{img_name}_sobel.jpg")

main()
