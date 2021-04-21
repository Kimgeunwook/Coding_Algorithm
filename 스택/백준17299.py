import sys
from _collections import deque
from collections import Counter

N = int(input())
arr = list(map(int, sys.stdin.readline().split()))
dic = [0 for _ in range(1000001)]
for i in range(N):
    dic[arr[i]] = dic[arr[i]] + 1
#dic = Counter(arr)
answer = [-1 for _ in range(N)]

dq = deque()

for idx in range(N):
    cur = arr[idx]

    while dq:
        if dic[cur] > dq[-1][1]:
            answer[dq[-1][0]] = cur
            dq.pop()
        else:
            break
    dq.append((idx, dic[cur]))

for idx in range(N):
    print(answer[idx], end=' ')

