import math

def main():
    temp = input("")
    temp = temp.split()
    n0 = int(temp[0])
    w0 = int(temp[1])
    list = [] # wi, vi
    for i in range(n0):
        temp = input("")
        temp = temp.split()
        list.append([int(temp[0]), int(temp[1])])
    


main()