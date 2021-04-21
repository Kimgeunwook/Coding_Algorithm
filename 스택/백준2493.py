import sys
from _collections import deque

N = int(input())
answer = [0 for _ in range(N)]
arr = list(map(int, sys.stdin.readline().split()))

dq = deque()
dq.append((N -1, arr[N - 1]))
for idx in range(N -2, -1, -1):
    while dq:
        if arr[idx] >= dq[-1][1]:
            answer[dq[-1][0]] = idx + 1
            dq.pop()
        else:
            break
    dq.append((idx, arr[idx]))

for i in range(N):
    print(answer[i], end=' ')