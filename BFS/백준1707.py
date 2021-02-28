from collections import deque
import sys
input = sys.stdin.readline
def init():
    global arr, visit
    for idx in range(20001):
        arr[idx].clear()
        visit[idx] = 0

def get_input():
    global V, arr
    V , E = map(int, input().split())
    for idx in range(E):
        a, b = map(int, input().split())
        arr[a].append(b)
        arr[b].append(a)

def bfs(idx):
    global V, arr, visit
    visit[idx] = 1
    dq = deque()
    dq.append(idx)
    while dq:
        cur = dq.popleft()
        for jdx in range(len(arr[cur])):
            next = arr[cur][jdx]
            if visit[next] == 0:
                visit[next] = -1 * visit[cur]
                dq.append(next)
            elif visit[cur] == visit[next]:
                return False
    return True

def simulation():
    global V, arr, visit
    for idx in range(1, V + 1):
        if visit[idx] == 0:
            if bfs(idx) == False:
                return False
    return True


V = 0
arr = [[] for _ in range(20001)]
visit = [0 for _ in range(20001)]
for _ in range(int(input())):
    init()
    get_input()
    if simulation():
        print('YES')
    else:
        print("NO")
