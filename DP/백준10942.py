import sys
N = int(sys.stdin.readline())
arr = list(map(int,sys.stdin.readline().split()))


dp = [[0 for _ in range(N)] for _ in range(N)]

for idx in range(N):
    for jdx in range(N):
        if idx == jdx:
            dp[idx][jdx] = 1

for idx in range(N - 1):
    if arr[idx] == arr[idx + 1]:
        dp[idx][idx + 1] = 1

for K in range(2, N):
    for idx in range(N):
        if idx + K < N:
            if arr[idx] == arr[idx + K] and dp[idx + 1][idx + K - 1]:
                dp[idx][idx + K] = 1


k = int(sys.stdin.readline())
for idx in range(k):
    a, b = map(int,sys.stdin.readline().split())
    print(dp[a - 1][b - 1])