from itertools import combinations
import copy
def search():
    for j in range(1,N+1):
        cur_location = j
        for i in range(1, H + 1):
            if cur_location == 1:
                if _map[i][cur_location] == 1:
                    cur_location += 1
            elif cur_location == N:
                if _map[i][cur_location - 1] == 1:
                    cur_location -= 1
            else:
                if _map[i][cur_location] == 1 :
                    cur_location += 1
                elif _map[i][cur_location - 1] == 1:
                    cur_location -= 1
        if cur_location != j:
            return -1
    return 1

def bfs():
    if search() == 1:
        return 0

    for i in range(1,4):
        for j in combinations(comb_list,i):
            #temp = copy.deepcopy(_map)
            a = []
            for k in j:
                if _map[k[0]][k[1]] == 1 or _map[k[0]][k[1] - 1] or _map[k[0]][k[1] + 1]:
                    continue
                _map[k[0]][k[1]] = 1
                a.append((k[0],k[1]))
            if search() == 1:
                return i
            for m in a:
                _map[m[0]][m[1]] = 0
    return -1



N, M, H = list(map(int,input().split()))
_map = [[0]*(N + 2) for _ in range(H + 2)]

comb_list = []
for i in range(1, H + 1):
    for j in range(1, N):
        comb_list.append((i,j))

for i in range(M):
    a, b = list(map(int,input().split()))
    _map[a][b] = 1

ans = bfs()
print(ans)
