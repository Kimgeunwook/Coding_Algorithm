#################variable
arr = []
visit = [[0 for _ in range(4)] for _ in range(4)]
_max = 0
horizontal = 1
vertical = 0

def get_start():
    global visit, row, col
    for idx in range(row):
        for jdx in range(col):
            if visit[idx][jdx] == 0:
                return idx, jdx
    return -1, -1 #visit이 다 차서 끝내야할때

def attach_visit(x, y, _len, direction):
    global horizontal, vertical, visit
    if direction == horizontal:
        for idx in range(_len + 1):
            visit[x][y + idx] = 1
    else:
        for idx in range(_len + 1):
            visit[x + idx][y] = 1

def detach_visit(x, y, _len, direction):
    global horizontal, vertical, visit
    if direction == horizontal:
        for idx in range(_len + 1):
            visit[x][y + idx] = 0
    else:
        for idx in range(_len + 1):
            visit[x + idx][y] = 0

def visit_check(x, y, _len, direction):
    global horizontal, vertical, visit
    if direction == horizontal:
        for idx in range(_len + 1):
            if visit[x][y + idx] == 1:
                return False
    else:
        for idx in range(_len + 1):
            if visit[x + idx][y] == 1:
                return False

    return True

def getnum(x, y, _len, direction):
    global horizontal, vertical, arr
    temp = ""
    if direction == horizontal:
        for idx in range(_len + 1):
            temp = temp + arr[x][y + idx]
    else:
        for idx in range(_len + 1):
            temp = temp + arr[x + idx][y]


    if temp.lstrip('0') == "":
        return 0
    return int(temp.lstrip('0'))



def dfs(sum):
    global horizontal, vertical, row, col, _max
    x, y = get_start()
    if x == -1 and y == -1:
        _max = max(_max, sum)
        return

    for idx in range(4):
        if (y + idx < col) and visit_check(x, y, idx, horizontal) :
            attach_visit(x, y, idx, horizontal)
            dfs(sum + getnum(x, y , idx, horizontal))
            detach_visit(x, y, idx, horizontal)
        if (x + idx < row) and visit_check(x, y, idx, vertical) :
            attach_visit(x, y, idx, vertical)
            dfs(sum + getnum(x, y, idx, vertical))
            detach_visit(x, y, idx, vertical)



###################input
row, col = list(map(int, input().split()))
for i in range(row):
    arr.append(input())
##################solve
dfs(0)
print(_max)

