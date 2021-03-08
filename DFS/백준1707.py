import sys
sys.setrecursionlimit(200000)
def init():
    global arr, color
    for idx in range(20001):
        arr[idx].clear()
        color[idx] = 0


def get_input():
    global V,E, arr
    V, E = map(int, input().split())
    for idx in range(E):
        a, b = map(int, input().split())
        arr[a].append(b)
        arr[b].append(a)

def dfs(i, n):
    global V, arr, color
    for idx in range(len(arr[i])):
        if color[arr[i][idx]] == 0:
            color[arr[i][idx]] = n * -1
            dfs(arr[i][idx], n * -1)

def get_dfs():
    global V, arr, color
    for idx in range(1, V + 1):
        if color[idx] == 0:
            color[idx] = 1
            dfs(idx, 1)

def solve():
    global V,arr, color
    for idx in range(1, V + 1):
        for jdx in range(len(arr[idx])):
            if(color[idx] == color[arr[idx][jdx]]):
                return "NO"
    return "YES"

V = 0
color = [0 for _ in range(20001)]
arr = [[] for _ in range(20001)]
Testcase = int(input())
for k in range(Testcase):
    init()
    get_input()
    get_dfs()
    print(solve())




