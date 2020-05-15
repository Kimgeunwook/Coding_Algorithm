# array = [[0]*N]*M
from itertools import combinations
import copy
from collections import deque

def search(temp_map, x, y, temp_visit):
    for i in range(-1,2):
        for j in range(-1,2):
            if i * j ==0 and not(i == 0 and j == 0) :
                if x + i >= 0 and x + i < N and y + j >= 0 and y + j < M:
                    if temp_map[x + i][y + j] == 0 and temp_visit[x + i][y + j] == 0:
                        temp_visit[x + i][y + j] = 1
                        temp_map[x + i][y + j] = 2
                        search(temp_map, x + i, y + j,temp_visit)


def calc(temp_map):
    _cnt = 0
    for i in range(N):
        for j in range(M):
            if(temp_map[i][j] == 0):
                _cnt += 1
    return _cnt




N, M = map(int,input().split())
_map = [ list(map(int, input().split())) for i in range(N)]

virus = deque()
comb_list_all = []

for i in range(N):
    for j in range(M):
        if _map[i][j] == 0:
            comb_list_all.append((i,j))
        if(_map[i][j] == 2):
            virus.append((i,j))

comb_list = list(combinations(comb_list_all,3))
_max = 0

for i in comb_list:
    false_map = copy.deepcopy(_map)
    false_map[i[0][0]][i[0][1]] = 1
    false_map[i[1][0]][i[1][1]] = 1
    false_map[i[2][0]][i[2][1]] = 1
    visit = [[0]*M for _ in range(N)]
    for vi in virus:
        cur_x = vi[0]
        cur_y = vi[1]
        visit[cur_x][cur_y] = 1
        search(false_map, cur_x, cur_y,visit)
    _max = max(_max, calc(false_map))
print(_max)
