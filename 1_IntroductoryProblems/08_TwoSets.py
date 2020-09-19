# Your task is to divide the numbers 1,2,…,n into two sets of equal sum.

# Input
# The only input line contains an integer n.

# Output
# Print "YES", if the division is possible, and "NO" otherwise.

# After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.
# Constraints
#     1≤n≤106

# Example 1
# Input:
# 7
# Output:
# YES
# 4
# 1 2 4 7
# 3
# 3 5 6

if __name__ == "__main__":
    n = int(input())
    if ((n*(n+1))/2) % 2:
        print("NO")
    else:
        print("YES")
        l1, l2 = [n], [n-1]
        diff = 1
        for i in range(n-2, 0, -1):
            if diff > 0:
                l2.append(i)
                diff -= i
            else:
                l1.append(i)
                diff += i
        print(len(l1))
        print(*l1, sep=" ")
        print(len(l2))
        print(*l2, sep=" ")
