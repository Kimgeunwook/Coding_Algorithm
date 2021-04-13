#13:00시작
import sys
import heapq
from _collections import deque

#구역나누기 세부
def put_num(x, y, color):
    dq = deque()
    dq.append((x,y))
    visit[x][y] = True
    arr[x][y] = color
    while dq:
        cur = dq.popleft()
        for idx in range(4):
            nx = cur[0] + dx[idx]
            ny = cur[1] + dy[idx]
            if nx >= 0 and ny >= 0 and nx < N and ny < M:
                if arr[nx][ny] == 1 and visit[nx][ny] == 0:
                    visit[nx][ny] = 1
                    dq.append((nx,ny))
                    arr[nx][ny] = color

def bfs(x, y, dir):
    curx = x
    cury = y
    cnt = -1
    while 1:
        nx = curx + dx[dir]
        ny = cury + dy[dir]
        cnt = cnt + 1
        if nx < 0 or ny < 0 or nx >= N or ny >= M:
            break
        if arr[nx][ny] != 0:
            if cnt >= 2:
                dist[arr[nx][ny]] = min(dist[arr[nx][ny]], cnt)
            break
        curx = nx
        cury = ny

def is_edge(x, y):
    if x - 1 >= 0 and arr[x - 1][y] == 0:
        return True
    if x + 1 < N and arr[x + 1][y] == 0:
        return True
    if y - 1 >= 0 and arr[x][y - 1] == 0:
        return True
    if y + 1 < M and arr[x][y + 1] == 0:
        return True
    return False

def _find(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = _find(parent[x])
        return parent[x]

def _union(x, y):
    x = _find(x)
    y = _find(y)
    parent[x] = y

def all_same():
    cur = _find(parent[1])
    for idx in range(2, NUM + 1):
        if cur != _find(parent[idx]): return False

    return True

#####main
#input
N, M = list(map(int, sys.stdin.readline().split()))
arr = []
visit = [[0 for _ in range(M)] for _ in range(N)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0 ,1]

for idx in range(N):
    arr.append(list(map(int, sys.stdin.readline().split())))

#구역 나누기
NUM = 0
for idx in range(N):
    for jdx in range(M):
        if arr[idx][jdx] != 0 and visit[idx][jdx] == 0:
            NUM = NUM + 1
            put_num(idx, jdx, NUM)

pq = []
for K in range(1, NUM + 1):
    dist = [1000 for _ in range(NUM + 1)]
    for idx in range(N):
        for jdx in range(M):
            if arr[idx][jdx] == K and is_edge(idx, jdx):
                for dir in range(4):
                    bfs(idx, jdx, dir)

    #pq에 거리순으로 넣기
    for i in range(1, NUM + 1):
        if dist[i] != 0:
            heapq.heappush(pq,(dist[i], K, i))


parent = []
for idx in range(NUM + 1):
    parent.append(idx)
answer = 0

while pq:
    cur = heapq.heappop(pq)
    if _find(cur[1]) != _find(cur[2]) and cur[0] < 1000:
        _union(cur[1], cur[2])
        answer = answer + cur[0]
    if all_same():
        break

if all_same():
    print(answer)
else:
    print(-1)







