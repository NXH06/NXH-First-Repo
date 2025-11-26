import math

print("Enter number: ")
n = int(input())
ret = []
a = 1
b = 1

###
for a in range (1, n + 1):
    for b in range (1, n + 1):
        if math.gcd(a, b) == 1:
                ret.append((a, b)) # the inner brackets: convert a & b into a tuple, since ret.append takes only 1 argument

###
ret.sort(key = lambda e: e[0] / e[1])
print(ret)