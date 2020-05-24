import copy
def rotate_left(idx):
    temp = copy.deepcopy(cube)
    for j in range(3):
        for i in range(2,-1,-1):
            cube[idx][i][j] = temp[idx][j][2 - i]
def rotate_right(idx):
    temp = copy.deepcopy(cube)
    cube[idx][0][0] = temp[idx][2][0]
    cube[idx][0][1] = temp[idx][1][0]
    cube[idx][0][2] =temp[idx][0][0]
    cube[idx][1][0] = temp[idx][2][1]
    cube[idx][1][1] = temp[idx][1][1]
    cube[idx][1][2] = temp[idx][0][1]
    cube[idx][2][0] = temp[idx][2][2]
    cube[idx][2][1] = temp[idx][1][2]
    cube[idx][2][2] = temp[idx][0][2]

def move(idx1,dir1,reverse, idx2,dir2,temp):
    before =[]
    if dir1 == 1: #윗
        if reverse == 1:
            for i in range(2,-1,-1):
                before.append(temp[idx1][0][i])
        else:
            for i in range(3):
                before.append(temp[idx1][0][i])

    elif dir1 == 2: #오른
        if reverse == 1:
            for i in range(2,-1,-1):
                before.append(temp[idx1][i][2])
        else:
            for i in range(3):
                before.append(temp[idx1][i][2])

    elif dir1 == 3: #왼
        if reverse == 1:
            for i in range(2,-1,-1):
                before.append(temp[idx1][i][0])
        else:
            for i in range(3):
                before.append(temp[idx1][i][0])

    elif dir1 == 4: #밑
        if reverse == 1:
            for i in range(2,-1,-1):
                before.append(temp[idx1][2][i])
        else:
            for i in range(3):
                before.append(temp[idx1][2][i])

    if dir2 == 1: #윗
        for i in range(3):
            cube[idx2][0][i] = before[i]
    elif dir2 == 2:#오른
        for i in range(3):
            cube[idx2][i][2] = before[i]
    elif dir2 == 4:#아래
        for i in range(3):
            cube[idx2][2][i] = before[i]
    elif dir2 == 3:#왼
        for i in range(3):
            cube[idx2][i][0] = before[i]

#큐브만들기
cube = []
colors = ['w', 'y', 'r', 'o', 'g', 'b'] #위0 아래1 앞2 뒷3 왼4 오5
for i in range(6):
    foo = []
    for j in range(3):
        tempp = []
        for k in range(3):
            tempp.append(colors[i])
        foo.append(tempp)
    cube.append(foo)

N = int(input())
original = copy.deepcopy(cube)
for i in range(N):
    M = int(input())
    rotation = list(input().split())
    cube = copy.deepcopy(original)
    for j in rotation:
        temp = copy.deepcopy(cube)
        if j == 'U-':
            rotate_left(0)
            move(4, 1,0, 2, 1,temp) #윗줄 1 오른쪽 2 왼족 3 아랫줄 4
            move(2, 1,0, 5, 1,temp)
            move(5, 1,0, 3, 1,temp)
            move(3, 1,0, 4, 1,temp)
        elif j == 'U+':
            rotate_right(0)
            move(3, 1,0, 5, 1, temp)
            move(5, 1,0, 2, 1, temp)
            move(2, 1,0, 4, 1, temp)
            move(4, 1,0, 3, 1, temp)
        elif j == 'D-':
            rotate_left(1)
            move(3, 4,0, 5, 4, temp)
            move(5, 4,0, 2, 4, temp)
            move(2, 4,0, 4, 4, temp)
            move(4, 4,0, 3, 4, temp)

        elif j == 'D+':
            rotate_right(1)
            move(4, 4,0, 2, 4, temp)
            move(2, 4,0, 5, 4, temp)
            move(5, 4,0, 3, 4, temp)
            move(3, 4,0, 4, 4, temp)
        elif j == 'F-':
            rotate_left(2)
            move(0, 4,1, 4, 2, temp)
            move(4, 2,1, 1, 4, temp)
            move(1, 4,0, 5, 3, temp)
            move(5, 3,0, 0, 4, temp)

        elif j == 'F+':
            rotate_right(2)
            move(5, 3,0, 1, 4, temp)
            move(1, 4,1, 4, 2, temp)
            move(4, 2,1, 0, 4, temp)
            move(0, 4,0, 5, 3, temp)
        elif j == 'B-':
            rotate_left(3)
            move(0,1,0, 5, 2, temp)
            move(5, 2,0, 1, 1, temp)
            move(1, 1,1, 4, 3, temp)
            move(4, 3,1, 0, 1, temp)
        elif j == 'B+':
            rotate_right(3)
            move(4, 3,1, 1, 1, temp)
            move(1, 1,0, 5, 2, temp)
            move(5, 2,0, 0, 1, temp)
            move(0, 1,1, 4, 3, temp)
        elif j == 'L-':
            rotate_left(4)
            move(0, 3,1, 3, 2, temp)
            move(3, 2,0, 1, 2, temp)
            move(1, 2,1, 2, 3, temp)
            move(2, 3,0, 0 ,3, temp)
        elif j == 'L+':
            rotate_right(4)
            move(2, 3,1, 1, 2, temp)
            move(1, 2,0, 3, 2, temp)
            move(3, 2,1, 0, 3, temp)
            move(0, 3,0, 2, 3, temp)
        elif j == 'R-':
            rotate_left(5)
            move(1, 3,0, 3, 3, temp)
            move(3, 3,1, 0, 2, temp)
            move(0, 2,0, 2, 2, temp)
            move(2, 2,1, 1, 3, temp)
        elif j == 'R+':
            rotate_right(5)
            move(2, 2,0, 0, 2, temp)
            move(0, 2,1, 3, 3, temp)
            move(3, 3,0, 1, 3, temp)
            move(1, 3,1, 2, 2, temp)

    #출력
    for i in cube[0]:
        for j in i:
            print(j,end='')
        print()
