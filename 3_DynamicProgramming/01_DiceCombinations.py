if __name__ == "__main__":
    n = int(input())
    dp = [0, 0, 0, 0, 0, 1]
    s = sum(dp[-6:])
    while n:
        dp.append(s)
        s = s + s - dp.pop(0)
        n -= 1
    print(dp[-1] % 1000000007)
