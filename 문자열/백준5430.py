import sys
Test_case = int(sys.stdin.readline())

for t in range(Test_case):
    input_string = sys.stdin.readline().strip()
    n = int(sys.stdin.readline())
    input_arr = sys.stdin.readline().strip()[1:-1]
    if len(input_arr) == 0:
        input_arr = []
    else:
        input_arr = list(map(int, input_arr.split(',')))

    cur_direction = 1  # 1이 왼쪽에서 오른쪽 -1이 오른쪽에서 왼쪽
    left = 0
    right = len(input_arr)
    for idx in range(len(input_string)):

        if input_string[idx] == 'R':
            cur_direction = cur_direction * -1
        elif input_string[idx] == 'D':
            if cur_direction == 1:
                left = left + 1
            else:
                right = right - 1
    if right < left:
        print('error')
        continue
    elif left == right:
        print('[]')
        continue
    answer = ""
    answer = answer + '['
    if cur_direction == 1:
        for jdx in range(left, right):
            answer = answer + str(input_arr[jdx]) + ','
    else:
        for jdx in range(right -1, left - 1, -1):
            answer = answer + str(input_arr[jdx]) + ','

    answer = answer[:-1] + ']'
    print(answer)
