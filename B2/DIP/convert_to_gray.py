from PIL import Image

img = Image.open("cat (color).jpg")
img = img.convert("L") # convert to grayscale
img.save("cat.jpg") # note: the grayscale cat image is just named "cat.jpg" now