import sys

# input
N = int(input())
arr = list(map(int, sys.stdin.readline().split()))

answer = [-1 for _ in range(N)]
_stack = []

_stack.append((arr[0], 0))
for idx in range(1, N):  # 3 5 2 7
    while _stack and _stack[-1][0] < arr[idx]:
        answer[_stack[-1][1]] = arr[idx]
        _stack.pop()

    _stack.append((arr[idx], idx))

for item in answer:
    print(str(item) + " ", end='')
