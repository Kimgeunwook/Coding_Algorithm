
N, M = map(int, input().split())
arr = [input() for _ in range(N)]
K = int(input())

ans = 0
for idx1 in range(N):
    initial = arr[idx1]
    cnt = 0
    for idx2 in range(N):
        if initial == arr[idx2]:
            cnt += 1
    zerocnt = 0
    for i in range(len(initial)):
        if initial[i] == '0':
            zerocnt += 1

    if zerocnt <= K and (zerocnt % 2 == K % 2):
        ans = max(ans, cnt)
print(ans)
