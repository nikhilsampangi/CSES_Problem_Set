l1 = [int(input())]
while(l1[-1] != 1):
    l1.append((l1[-1]*3)+1 if l1[-1] % 2 else (l1[-1]//2))
print(*l1, sep=" ")
