N = int(input())
arr = []
_visit = [0 for _ in range(N + 1)]
_max = 0
for _ in range(N - 1):
    a, b, c = list(map(int, input().split()))
    arr.append((a,b,c))

for idx in range(len(arr) -1 , -1, -1):
    parent, child, weight = arr[idx]
    if _visit[parent] == 0: #처음 방문하는 부모노드면 
        _visit[parent] = weight + _visit[child]
        _max = max(_max, _visit[parent])
    else: #두번쨰 방문하는 부모노드면 -> 맥스값까지 갱신해줘야함
        _max = max(_max, _visit[parent] + weight + _visit[child])
        _visit[parent] = max(_visit[parent], weight + _visit[child])
print(_max)