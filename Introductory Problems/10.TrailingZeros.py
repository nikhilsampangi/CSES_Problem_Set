if __name__ == "__main__":
    n = int(input())
    p = 5
    sol = 0
    while n >= p:
        sol += n//p
        p = p*5
    print(sol)
