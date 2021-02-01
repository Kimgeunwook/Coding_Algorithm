def solve(idx):
    ret = 0
    if idx > 0:
        lefttemp = arr[idx] - arr[idx - 1]
        ret += 1
    if idx < N - 1:
        righttemp = arr[idx + 1] - arr[idx]
        ret += 1

    for i in range(idx - 1, -1, -1):
        if lefttemp > (arr[i] - arr[idx]) / (i - idx):
            ret += 1
            lefttemp = (arr[i] - arr[idx]) / (i - idx)

    for i in range(idx + 1, N):
        if righttemp < (arr[i] - arr[idx]) / (i - idx):
            ret += 1
            righttemp = (arr[i] - arr[idx]) / (i - idx)
    return ret


N = int(input())
arr = list(map(int, input().split()))
ans = 0
for idx in range(N):
    ans = max(ans, solve(idx))

print(ans)
