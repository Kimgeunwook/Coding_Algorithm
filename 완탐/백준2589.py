import sys
from _collections import deque

N, M = list(map(int, sys.stdin.readline().strip().split()))
arr = []
for idx in range(N):
    arr.append(list(sys.stdin.readline().strip()))

_max = 0
dq = deque()
dx = [-1, 0 ,1, 0]
dy = [0, 1, 0, -1]
visit = [[False for _ in range(M)] for _ in range(N)]

def init():
    global visit
    visit = [[False for _ in range(M)] for _ in range(N)]

def bfs():
    global _max
    while dq:
        cur = dq.popleft()
        if cur[2] > _max:
            _max = cur[2]

        for idx in range(4):
            nx = cur[0] + dx[idx]
            ny = cur[1] + dy[idx]
            if nx >= 0 and nx < N and ny >= 0 and ny < M:
                if visit[nx][ny] == False and arr[nx][ny] == 'L':
                    visit[nx][ny] = True
                    dq.append((nx, ny, cur[2] + 1))
def solve():
    for idx in range(N):
        for jdx in range(M):
            if arr[idx][jdx] == 'L':
                dq.append((idx, jdx, 0))
                init()
                visit[idx][jdx] = True
                bfs()

solve()
print(_max)