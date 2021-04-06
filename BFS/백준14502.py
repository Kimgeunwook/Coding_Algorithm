#import
from _collections import deque
import copy
import sys

#val
arr = []
copy_arr = []
dq = deque()
copy_dq = deque()
_max = 0
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

#input
N, M = list(map(int, input().split()))
for i in range(N):
    arr.append(list(map(int,sys.stdin.readline().split())))

for i in range(N):
    for j in range(M):
        if arr[i][j] == 2:
            copy_dq.append((i,j))
#_copy
def _copy():
    global copy_dq, copy_arr,dq, arr
    copy_arr = copy.deepcopy(arr)
    dq = copy.deepcopy(copy_dq)

#bfs
def bfs():
    while dq:
        cur = dq.popleft()

        for idx in range(4):
            nextx = cur[0] + dx[idx]
            nexty = cur[1] + dy[idx]
            if nextx >= 0 and nextx < N and nexty >= 0 and nexty < M:
                if copy_arr[nextx][nexty] == 0:
                    copy_arr[nextx][nexty] = 2
                    dq.append((nextx, nexty))

#get_max
def get_max():
    global   _max
    cnt = 0
    for i in range(N):
        for j in range(M):
            if copy_arr[i][j] == 0:
                cnt = cnt + 1

    _max = max(_max, cnt)

#comb
def comb(cnt):
    if cnt == 3:
        _copy()
        bfs()
        get_max()
    else:
        for i in range(N):
            for j in range(M):
                if arr[i][j] == 0:
                    arr[i][j] = 1
                    comb(cnt + 1)
                    arr[i][j] = 0


#main
comb(0)
print(_max)



