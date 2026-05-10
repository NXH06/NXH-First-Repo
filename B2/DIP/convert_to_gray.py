from PIL import Image

img_name = input("Image name: ")
img = Image.open(f"{img_name} (color).jpg")
img = img.convert("L") # convert to grayscale
img.save(f"{img_name}.jpg")