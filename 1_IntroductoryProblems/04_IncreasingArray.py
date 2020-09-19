n, sol = int(input()), 0
l1 = [int(i) for i in input().split()]
for i in range(1, n):
    if (l1[i] < l1[i-1]):
        sol += l1[i-1]-l1[i]
        l1[i] = l1[i-1]
print(sol)
