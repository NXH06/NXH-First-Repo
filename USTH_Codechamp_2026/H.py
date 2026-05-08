

def main():
    temp = input("")
    temp = temp.split()
    n = int(temp[0])
    m = int(temp[1])
    paths = []
    amt = n
    for i in range(m):
        if amt == 0:
            break
        temp = input("")
        temp = temp.split()
        u = int(temp[0]) - 1
        v = int(temp[1]) - 1
        if u > v:
            swap = u
            u = v
            v = swap
        if [u, v] not in paths[u]:
            paths[u].append([u, v])
    print(amt)

main()
