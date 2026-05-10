def find_remainder(n: int, mod: int): # find remainder of (2^n) % mod
    if n == 1:
        return 2
    elif n % 2 == 0:
        return (find_remainder(n // 2, mod) ** 2) % mod
    elif n % 2 == 1:
        return (find_remainder(n // 2, mod) ** 2 * 2) % mod

def main():
    n = int(input(""))
    mod = 10 ** 9 + 7
    print(find_remainder(n, mod))

main()