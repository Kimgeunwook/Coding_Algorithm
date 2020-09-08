N = int(input())
arr = list(map(int,input().split()))
temp =[0]
dp = [0]
for i in arr:
    temp.append(i)
    dp.append(i)

for i in range(1, N + 1):
    for j in range(i):
        dp[i] = max(dp[i], dp[j] + dp[i - j] )

print(dp[N])

