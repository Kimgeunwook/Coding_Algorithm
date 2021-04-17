from _collections import deque

N, M = list(map(int, input().split()))
arr = [[] for _ in range(N + 1)] #간선 저장하는 배열
indegree = [0 for _ in range(N + 1)] #차수 저장 배열
dq = deque() #indegree가 0인애를 저장하는 배열
result = [] #결과 출력할때 사용할 배열

#입력
for i in range(M):
    a, b = list(map(int, input().split()))
    arr[a].append(b)
    indegree[b] = indegree[b] + 1

#indegree 0인 index를 queue에 넣어주기
for i in range(1, N + 1):
    if indegree[i] == 0:
        dq.append(i)

#어쨋든 n개끼리의 순서니까 n번 반복
for idx in range(N):
    cur = dq.popleft()
    result.append(cur)

    #지금 출력되는애가 나가면 indegree가 0이 되는애가 있는지 체크
    for jdx in range(len(arr[cur])):
        tmp = arr[cur][jdx]

        indegree[tmp] = indegree[tmp] - 1
        if indegree[tmp] == 0:
            dq.append(tmp)

#출력
for idx in range(N):
    print(result[idx], '', end ='')





