from PIL import Image
import numpy as np

def weighted_avg(arr: np.ndarray):
    radius = 1 # to simplify things, each region has only 9 pixels.
    """For radius 1 blur, set all weights to 1"""
    w_center = 4
    w_side = 2
    w_corner = 1
    for row in range(radius, arr.shape[0] - radius):
        for col in range(radius, arr.shape[1] - radius):
            region = np.array(arr[row-radius:row+radius+1, col-radius:col+radius+1])
            kernel = np.array(
            [[w_corner, w_side, w_corner],
            [w_side, w_center, w_side],
            [w_corner, w_side, w_corner]])
            kernel = np.divide(kernel, np.sum(kernel))
            arr[row][col] = np.sum(region * kernel)
    return Image.fromarray(arr)

def main():
    img = Image.open("cat.jpg")
    arr = np.array(img)
    img_processed = weighted_avg(arr)
    img_processed.save("cat_weighted_avg.jpg")

main()
