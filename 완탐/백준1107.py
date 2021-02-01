#15:20시작
def dfs(cnt):
    global minvalue
    if cnt == len(str(N)) or cnt == len(str(N)) - 1 or cnt == len(str(N)) + 1:
        if cnt == len(str(N)) or cnt == len(str(N)) - 1:
            for i in ablenum:
                temp.append(str(i))
                dfs(cnt + 1)
                temp.pop()
        num = 100
        if len(temp) > 0:
            num = int("".join(temp))
        minvalue = min(minvalue, abs(num - N) + len(str(num)))
    else:
        for i in ablenum:
            temp.append(str(i))
            dfs(cnt + 1)
            temp.pop()

N = int(input())
unableNum = int(input())
ablenum = []
if unableNum != 0:
    arr = list(map(int, input().split()))
else :
    arr = []
for i in range(10):
    if i not in arr:
        ablenum.append(i)

temp = []
minvalue = abs(N - 100)

dfs(0)

print(minvalue)

