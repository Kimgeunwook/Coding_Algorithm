def solution(dirs):
    answer = 0
    map = [[[0 for col in range(11)] for row in range(11)] for depth in range(4)]
    cur_x =5
    cur_y = 5
    for i in range(len(dirs)):
        print(cur_x,cur_y)
        if dirs[i] == 'U':#범위 넘어가는거 추가
            if cur_x - 1 < 0:
                continue
            if map[0][cur_x][cur_y] == 0 and map[2][cur_x - 1][cur_y] == 0:
                print(cur_x, cur_y)
                answer += 1
                map[0][cur_x][cur_y] = 1
            cur_x -= 1


        elif dirs[i] == 'R':
            if cur_y + 1 > 10:
                continue
            if map[1][cur_x][cur_y] == 0 and map[3][cur_x][cur_y + 1] == 0:
                print(cur_x, cur_y)
                answer +=1
                map[1][cur_x][cur_y] = 1
            cur_y += 1

        elif dirs[i] == 'L':
            if cur_y - 1 < 0:
                continue
            if map[3][cur_x][cur_y] == 0 and map[1][cur_x][cur_y - 1] == 0:
                print(cur_x,cur_y)
                answer += 1
                map[3][cur_x][cur_y] = 1
            cur_y -= 1
        elif dirs[i] == 'D':
            if cur_x + 1 > 10:
                continue
            if map[2][cur_x][cur_y] == 0 and map[0][cur_x + 1][cur_y]==0:
                print(cur_x, cur_y)
                answer += 1
                map[2][cur_x][cur_y] = 1
            cur_x += 1
    print(cur_x,cur_y)
    return answer

print(solution("LULLRDRLLU"))
