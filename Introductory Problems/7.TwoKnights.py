if __name__ == "__main__":
    for i in range(1, int(input())+1):
        sol = (((i*i)*(i*i - 1))/2) - (4*(i-1)*(i-2))
        print(int(sol))
