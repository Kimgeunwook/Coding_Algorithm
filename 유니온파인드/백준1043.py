# 2031
def Union(x, y):
    x = Find(x)
    y = Find(y)
    parent[x] = y


def Find(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = Find(parent[x])
        return parent[x]


parent = [i for i in range(51)]
N, M = map(int, input().split())
knowingPeople = list(map(int, input().split()))
knowingPeople = knowingPeople[1:]
thief = []
for i in knowingPeople:
    thief.append(i)

arr = []
for idx in range(M):
    temp = list(map(int, input().split()))
    temp = temp[1:]
    arr.append(temp)
    N1 = temp[0];
    for j in temp:
        Union(j, N1)

ans = 0
for idx in range(len(arr)):
    flag = 0
    for i in arr[idx]:
        for j in thief:
            if Find(i) == Find(j):
                flag = 1
                break
        if flag == 1:
            break
    if flag == 0:
        ans += 1
print(ans)





