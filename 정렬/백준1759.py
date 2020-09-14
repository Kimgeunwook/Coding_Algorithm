def solve(arr, cnt, idx):
    global N,M,temp,answer
    if cnt == N:
        flag = 0
        flaglist =['a', 'e', 'i', 'o', 'u']
        for item in flaglist:
            if item in temp:
                flag += 1
        if flag >=1 and flag <= N - 2:
            print("".join(temp))
    else:
        for i in range(idx, M):
            temp.append(arr[i])
            solve(arr,cnt + 1, i + 1)
            temp.pop()





inputlist = list(map(int,input().split()))
global N, M,temp,answer
answer =[]
N = inputlist[0]
M = inputlist[1]
temp =[]
arr = list(map(str,input().split()))
arr.sort()
solve(arr,0, 0)

