n = int(input())
if n < 4:
    print("NO SOLUTION") if n != 1 else print(1)
else:
    l1 = [i for i in range(2, n+1, 2)]
    l2 = [i for i in range(1, n+1, 2)]
    print(*(l1+l2), sep=" ")
