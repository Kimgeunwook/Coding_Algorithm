# 16:48시작
def dfs(x, y, cnt, p):
    global N, ans
    if cnt == N:
        ans += p
    else:
        for idx in range(4):
            nextx = x + dx[idx]
            nexty = y + dy[idx]

            if visit[nextx][nexty] == 0:
                visit[nextx][nexty] = 1
                dfs(nextx, nexty, cnt + 1, p * arr[idx])
                visit[nextx][nexty] = 0


arr = list(map(int, input().split()))
N = arr[0]
arr = arr[1:]  # 동 서 남 북
for idx in range(len(arr)):
    num = int(arr[idx]) / 100
    arr[idx] = num

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
visit = [[0 for _ in range(29)] for _ in range(29)]
visit[14][14]= 1
ans = 0

dfs(14, 14, 0, 1)
print(ans)

