from PIL import Image
import numpy as np

def blur(arr: np.ndarray, radius: int):
    edge_pixel_count = radius * 2 + 1
    for row in range(radius, arr.shape[0] - radius):
        for col in range(radius, arr.shape[1] - radius):
            region = np.array(arr[row-radius:row+radius+1, col-radius:col+radius+1])
            kernel = np.array([[1] * edge_pixel_count] * edge_pixel_count)
            kernel = np.divide(kernel, region.size)
            arr[row][col] = np.sum(region * kernel)
    print(arr)
    return Image.fromarray(arr)

def main():
    img = Image.open("cat.jpg")
    arr = np.array(img)
    radius = 1
    img_processed = blur(arr, radius)
    img_processed.save("cat_blur.jpg")

main()
