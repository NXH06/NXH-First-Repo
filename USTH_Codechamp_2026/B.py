import math

def main():
    temp = input("").split()
    a = int(temp[0])
    b = int(temp[1])
    amt = 0
    if (a > b):
        temp = a
        a = b
        b = temp
    print(math.gcd(a, b))


main()
