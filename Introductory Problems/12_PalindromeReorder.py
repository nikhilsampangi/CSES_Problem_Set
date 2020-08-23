if __name__ == "__main__":
    d1 = {}
    for i in str(input()):
        d1[i] = d1[i]+1 if i in d1 else 1
    count, s1, s2, odd = 0, '', '', ''
    for key, val in d1.items():
        temp = key*(val//2)
        s1 = temp+s1
        s2 = s2+temp
        if val % 2:
            count += 1
            odd = key
    if count > 1:
        print("NO SOLUTION")
    else:
        print(s1+odd+s2)
