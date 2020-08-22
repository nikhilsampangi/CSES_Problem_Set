def FindNumber(ip):
    mx = max(ip[0], ip[1])
    mn = min(ip[0], ip[1])
    val = (mx-1)**2 + mn
    if (mx % 2 == 0 and ip[1] < ip[0]) or (mx % 2 == 1 and ip[1] > ip[0]):
        val = val + (mx-mn)*2
    return val


if __name__ == "__main__":
    n = int(input())
    sol = []
    while n > 0:
        n -= 1
        sol.append(FindNumber([int(x) for x in input().split()]))
    for x in sol:
        print(x)
