from PIL import Image
import numpy as np

img_name = input("Image name: ")
img = Image.open(f"{img_name}.jpg")
arr = np.array(img) # grayscale image format: [height, width]

histogram = [0] * 64 # normally 256, but scaled down to fit in terminal
for row in arr:
    for col in row:
        histogram[int(col / 4)] += 1 # gray values scaled down to fit in 64 values

size = img.size[0] * img.size[1]
for i in range(64):
    print(f"[{i * 4}, {i * 4 + 3}]" + "|" * (int(histogram[i] / 50) + 1)) # all sample counts scaled down by 50 to fit in terminal
    #print(f"Value {i} | {histogram[i]} ({histogram[i] / size}%)")
