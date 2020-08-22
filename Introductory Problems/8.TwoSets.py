if __name__ == "__main__":
    n = int(input())
    if ((n*(n+1))/2) % 2:
        print("NO")
    else:
        print("YES")
        l1, l2 = [n], [n-1]
        diff = 1
        for i in range(n-2, 0, -1):
            if diff > 0:
                l2.append(i)
                diff -= i
            else:
                l1.append(i)
                diff += i
        print(len(l1))
        print(*l1, sep=" ")
        print(len(l2))
        print(*l2, sep=" ")
