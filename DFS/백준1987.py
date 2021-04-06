#1630시작
import sys

#input and value
N, M = list(map(int, input().split()))
arr = []
visit = [0 for _ in range(26)] #알파벳 방문 체크 배열
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
for i in range(N):
    arr.append(sys.stdin.readline().strip())

_max = 1

def dfs(x, y, depth):
    global _max
    _max = max(_max, depth)
    for idx in range(4):
        nx = x + dx[idx]
        ny = y + dy[idx]
        if nx >= 0 and nx < N and ny >= 0 and ny < M:
            if visit[ord(arr[nx][ny]) - ord('A')] == 0:
                visit[ord(arr[nx][ny]) - ord('A')] = 1
                dfs(nx, ny, depth + 1)
                visit[ord(arr[nx][ny]) - ord('A')] = 0

visit[ord(arr[0][0]) - ord('A')] = 1
dfs(0, 0, 1)
print(_max)


