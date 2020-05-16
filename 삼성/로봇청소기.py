from _collections import deque
def calc():
    ret = 0
    for i in range(N):
        for j in range(M):
            if(_map[i][j] == 2):
                ret += 1
    return ret
def set_dir(n, m):
    if(n - m < 0):
        return 4 - (m - n)
    else:
        return n - m
def dfs():
    while dq:
        _cnt = 0
        for i in range(1,5):
            cur_x = dq[-1][0]
            cur_y = dq[-1][1]
            cur_dir = set_dir(dq[-1][2],i)
            if _map[cur_x + dir[0][cur_dir]][cur_y + dir[1][cur_dir]] == 0:
                _map[cur_x + dir[0][cur_dir]][cur_y + dir[1][cur_dir]] = 2;
                dq.append((cur_x + dir[0][cur_dir], cur_y + dir[1][cur_dir], cur_dir))
                break;
            else :
                _cnt += 1
            if (_cnt == 4):
                if _map[cur_x - dir[0][cur_dir]][cur_y - dir[1][cur_dir]] != 1:
                    dq.append((cur_x - dir[0][cur_dir], cur_y - dir[1][cur_dir], cur_dir))
                    break
                else :
                 return




dir =[[-1,0,1,0],[0,1,0,-1]]
dq = deque()
N,M = map(int,input().split())
first_x, first_y, first_dir = map(int,input().split())
_map = [list(map(int,input().split())) for _ in range(N) ]

dq.append((first_x, first_y, first_dir))
_map[first_x][first_y] = 2
dfs()
print(calc())

