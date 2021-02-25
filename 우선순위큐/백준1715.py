import heapq
import sys
heap = []

N = int(input())
if N == 1:
    print(0)
    sys.exit()

for idx in range(N):
    a = int(input())
    heapq.heappush(heap, a)

answer = 0

while len(heap):
    first = heapq.heappop(heap)
    second = heapq.heappop(heap)
    answer = answer + first + second
    if len(heap) > 0:
        heapq.heappush(heap, first + second)

print(answer)

