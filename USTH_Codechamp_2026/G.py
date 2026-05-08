

def main():
    temp = input("")
    temp = temp.split()
    n = int(temp[0])
    k = int(temp[1])
    temp = input("")
    temp = temp.split()
    weights = []
    for i in range(n):
        weights.append(int(temp[i]))
    q = int(input(""))
    left = []
    for i in range(q):
        temp = input("")
        left.append(int(temp) - 1)
    #print(f"n: {n}, k: {k}, weights: {weights}, left: {left}")
    right = n - 1
    minpos = []
    minpos2 = []
    for i in range(q):
        pos = -1
        sum = 0
        amt = 0
        for j in range(left[i], right + 1):
            for k in range(len(minpos)):
                if j == minpos[k]:
                    if sum == amt * k:
                        pos = minpos2[k]
                        break
            sum += weights[j]
            amt += 1
            if (sum == amt * k):
                minpos.append(left[i])
                minpos2.append(j)
                break
        print(pos)
        #print(f"sum and length and average: {sum}, {length}, {sum/length}")
        #print(f"{left[i]}, {right}")

main()