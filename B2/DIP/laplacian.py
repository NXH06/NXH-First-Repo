from PIL import Image
import numpy as np

def laplacian(arr: np.ndarray):
    radius = 1 # to simplify things, each region has only 9 pixels.
    """Some filters:
    - Simple Laplacian: 4, -1, 0
    - Laplacian variant: 8, -1, -1
    - Blur: 1, 1, 1"""
    w_center = -8
    w_side = 1
    w_corner = 1
    output = arr.copy() # derivative filters require calculation on original pixels
    for row in range(radius, arr.shape[0] - radius):
        for col in range(radius, arr.shape[1] - radius):
            region = np.array(arr[row-radius:row+radius+1, col-radius:col+radius+1])
            kernel = np.array(
            [[w_corner, w_side, w_corner],
            [w_side, w_center, w_side],
            [w_corner, w_side, w_corner]])
            output[row][col] = np.sum(region * kernel)
    output = np.clip(output, 0, 255) # filter contains negative values, so output must be clipped into range
    output = np.subtract(arr, output)
    return Image.fromarray(output)

def main():
    img = Image.open("cat.jpg")
    arr = np.array(img)
    img_processed = laplacian(arr)
    img_processed.save("cat_laplacian.jpg")

main()
