from itertools import combinations
import copy
def search(temp):
    for j in range(1,N+1):
        cur_location = j
        for i in range(1, H + 1):
            if cur_location == 1:
                if temp[i][cur_location] == 1:
                    cur_location += 1
            elif cur_location == N:
                if temp[i][cur_location - 1] == 1:
                    cur_location -= 1
            else:
                if temp[i][cur_location] == 1 :
                    cur_location += 1
                elif temp[i][cur_location - 1] == 1:
                    cur_location -= 1
        if cur_location != j:
            return -1
    return 1

def bfs():
    if search(_map) == 1:
        return 0

    for i in range(1,4):
        comb = list(combinations(comb_list,i))
        for j in comb:
            temp = copy.deepcopy(_map)
            for k in j:
                if _map[k[0]][k[1]] == 1:
                    continue
                temp[k[0]][k[1]] = 1
            if search(temp) == 1:
                return i
    return -1



N, M, H = list(map(int,input().split()))
_map = [[0]*N for _ in range(H + 1)]

comb_list = []
for i in range(1, H + 1):
    for j in range(1, N):
        comb_list.append((i,j))

for i in range(M):
    a, b = list(map(int,input().split()))
    _map[a][b] = 1

ans = bfs()
print(ans)
