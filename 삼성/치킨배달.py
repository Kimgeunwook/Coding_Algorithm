from _collections import deque
import copy
_min = 987654321

def dfs(cnt):
    global _min
    if M == len(list_dfs):
        ret = 0
        for i in list_h:
            temp = 987654321
            for j in list_dfs:
                if temp > abs(i[0] - j[0]) + abs(i[1] - j[1]):
                    temp = abs(i[0] - j[0]) + abs(i[1] - j[1])
            ret += temp
        if _min > ret:
            _min = ret

    else:
        for i in range (cnt, len(list_c)):
            list_dfs.append(list_c[i])
            dfs(i + 1)
            list_dfs.pop()

list_c = []
list_dfs = []
list_h = []
dq = deque()
N, M = list(map(int,input().split()))
map = [list(map(int,input().split())) for _ in range(N)]
for i in range(N):
    for j in range(N):
        if map[i][j] == 2: #치킨집이면
            list_c.append((i,j))
        if map[i][j] == 1: #집이면
            list_h.append((i,j))
dfs(0)
print(_min)

