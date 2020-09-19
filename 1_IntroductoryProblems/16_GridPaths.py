# Working but too Slow
if __name__ == "__main__":
    sol = 0
    ip = str(input())
    visited = [[False for i in range(7)] for j in range(7)]

    def pathFind(i, j, path):
        if (path > 48 or (i == 6 and j == 0)):
            if path == 48:
                global sol
                sol += 1
            return
        global visited
        visited[i][j] = True
        u = (i-1 >= 0) and (not visited[i-1][j])
        d = (i+1 <= 6) and (not visited[i+1][j])
        l = (j-1 >= 0) and (not visited[i][j-1])
        r = (j+1 <= 6) and (not visited[i][j+1])
        if ((not l) and (not r) and u and d) or ((not u) and (not d) and l and r):
            return
        global ip
        if ip[path] != '?':
            if ip[path] == 'U':
                d = l = r = False
            elif ip[path] == 'D':
                u = l = r = False
            elif ip[path] == 'L':
                u = d = r = False
            else:
                u = d = l = False
        if u:
            pathFind(i-1, j, path+1)
            visited[i-1][j] = False
        if d:
            pathFind(i+1, j, path+1)
            visited[i+1][j] = False
        if l:
            pathFind(i, j-1, path+1)
            visited[i][j-1] = False
        if r:
            pathFind(i, j+1, path+1)
            visited[i][j+1] = False

    pathFind(0, 0, 0)
    print(sol)
