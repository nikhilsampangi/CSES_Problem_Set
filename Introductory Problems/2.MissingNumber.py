n = int(input())
l1 = set([int(i) for i in input().split()])
l2 = set([i+1 for i in range(n)])
l1 = l2-l1
for i in l1:
    print(i)
