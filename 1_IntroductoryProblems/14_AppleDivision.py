def minDiffRec(arr, s_tot, n, s_cur):
    if(n == 0):
        return abs(s_tot - (2*s_cur))
    return min(minDiffRec(arr, s_tot, n-1, s_cur), minDiffRec(arr, s_tot, n-1, s_cur+arr[n-1]))


if __name__ == "__main__":
    n = int(input())
    ip = [int(i) for i in input().split()]
    tot_sum = sum(ip)
    print(minDiffRec(ip, tot_sum, n, 0))
