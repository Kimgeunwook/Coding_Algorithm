#1000 시작
N = int(input())
arr = [] #입력 받은 알파벳 문자열 들어가는곳
sum = [0 for _ in range(26)]
answer = 0
for i in range(N):
    arr.append(input())

def add_to_sum(_str):
    unit = 1
    for idx in range(len(_str)):
        cur_alpha = _str[-1 * (idx + 1)]
        sum[ord(cur_alpha) - ord('A')] = sum[ord(cur_alpha) - ord('A')] + unit
        unit = unit * 10


for item in arr:
    add_to_sum(item)

sort_arr = []
for i in sum:
    if i != 0:
        sort_arr.append(i)


sort_arr.sort(reverse=True)
init = 9
for i in sort_arr:
    answer = answer + init * i
    init = init - 1

print(answer)

