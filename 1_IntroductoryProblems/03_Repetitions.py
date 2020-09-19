mx, cnt, st = 1, 0, ''
for i in str(input()):
    if st == i:
        cnt += 1
    else:
        st = i
        cnt = 1
    mx = max(mx, cnt)
print(mx)
