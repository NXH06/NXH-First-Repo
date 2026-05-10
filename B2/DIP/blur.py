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
    return Image.fromarray(arr)

def main():
    img_name = input("Image name: ")
    img = Image.open(f"{img_name}.jpg")
    arr = np.array(img)
    radius = 4
    img_processed = blur(arr, radius)
    img_processed.save(f"{img_name}_blur.jpg")

main()
