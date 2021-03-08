import heapq
import sys
heap = [[] for _ in range(1001)]
N = int(input())
visit =  [0 for _ in range(N + 1)]

for idx in range(1, N + 1):
    d, w = map(int,sys.stdin.readline().split())
    for jdx in range(1, d + 1):
        heapq.heappush(heap[jdx], (-w, idx))

answer = 0
for idx in range(1000, 0, -1):
    while len(heap[idx]) > 0:
        first = heapq.heappop(heap[idx])
        if visit[first[1]] == 0:
            visit[first[1]] = 1
            answer = answer +  ( -1 * first[0])
            break

print(answer)