#input and setting
import sys
import heapq
N = int(input())
M = int(input())
arr = [[] for _ in range(N + 1)]
dist = [987654321 for _ in range(N + 1)]
pq = []
for i in range(M):
    start, end, cost = map(int, sys.stdin.readline().split())
    arr[start].append((end, cost))

start, end = map(int, sys.stdin.readline().split())

#solve
def Dijkstra():
    global start
    dist[start] = 0
    heapq.heappush(pq, (0, start))

    while pq:
        cur_cost, cur_position = heapq.heappop(pq)
        for item in arr[cur_position]:
            next, next_cost = item
            if dist[next] > cur_cost + next_cost:
                dist[next] = cur_cost + next_cost
                heapq.heappush(pq,(dist[next], next))


#output
Dijkstra()
print(dist[end])

