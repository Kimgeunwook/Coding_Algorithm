from itertools import combinations
from _collections import deque
import copy
flag = 0
def bfs(temp_map):
    global N, flag
    visit = [[0] * N for _ in range(N)]
    cnt = 0
    while dq:
        #print(dq)
        cur_x, cur_y, cur_cnt = dq.popleft()

        #print(cur_x, cur_y, cur_cnt)
        for i in range(-1,2):
            for j in range(-1, 2):
                if not(i == 0 and j == 0) and i * j == 0:
                    if cur_x + i >= 0 and cur_x + i < N and cur_y + j >= 0 and cur_y + j <N:
                        if visit[cur_x + i][cur_y + j] == 0:
                            if temp_map[cur_x + i][cur_y + j] == 2:
                                #print('찾음',cur_x + i, cur_y + j, cur_cnt + 1)
                                return cur_cnt + 1
                            visit[cur_x + i][cur_y + j] = 1
                            dq.append((cur_x + i, cur_y + j,cur_cnt + 1))


def search():
    global _min, flag
    for i in comb: #comb = [((2,3),(3,5),(5,6)),((2,3),(3,5),(5,6))]
        temp_map = copy.deepcopy(map)
        ret = 0
        dq.clear()
        for j in i: #i =((2,3),(5,3),(4,3))
            temp_map[j[0]][j[1]] = 0
        ###################print(i)
        for k in list_h: #i = (x,y)
            flag = 0
            dq.clear()
            dq.append((k[0],k[1],0))
            ret += bfs(temp_map)
            ############################print(k[0],k[1],ret)
        if _min > ret:
            _min = ret





_min = 987654321
list_h = []
list_c = []
dq =deque()
N, M = list(map(int,input().split()))
map = [list(map(int,input().split())) for _ in range(N)]

for i in range(N):
    for j in range(N):
        if map[i][j] == 2: #치킨집이면
            list_c.append((i,j))
        if map[i][j] == 1: #집이면
            list_h.append((i,j))

comb = list(combinations(list_c,len(list_c) - M))
search()
print(_min)