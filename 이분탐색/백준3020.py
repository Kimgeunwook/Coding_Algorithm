import sys
def lower_bound(arr, key):
    start = 0
    end = len(arr)
    while start < end:
        mid = (start + end) // 2
        if arr[mid] >= key:
            end = mid
        elif arr[mid] < key:
            start = mid + 1
    return end

#입력 부분
input_list = list(input().split())
N = int(input_list[0])
H = int(input_list[1])
down = []
up = []
for idx in range(N):
    input_list2 = sys.stdin.readline().split()
    num = int(input_list2[0])
    if idx % 2 == 0:
        down.append(num)
    else:
        up.append(num)

#solve
#getanswer
_min = 987654321
mincnt = 0

down.sort()
up.sort()
for idx in range(1, H + 1):
    downcnt = ( (N//2) -  lower_bound(down, idx) )
    upcnt =  ( (N//2) - lower_bound(up, H + 1 - idx) )
    if downcnt + upcnt < _min:
        _min = downcnt + upcnt
        mincnt = 1
    elif downcnt + upcnt == _min:
        mincnt = mincnt + 1


print(_min, mincnt)