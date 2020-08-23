def coinPiles(ip) -> str:
    x = ((2*ip[0])-ip[1])/3
    y = ((2*ip[1])-ip[0])/3
    return "YES" if (x >= 0 and y >= 0 and x.is_integer() and y.is_integer()) else "NO"


if __name__ == "__main__":
    sol = []
    for i in range(int(input())):
        sol.append(coinPiles([int(x) for x in input().split()]))
    for lines in sol:
        print(lines)
