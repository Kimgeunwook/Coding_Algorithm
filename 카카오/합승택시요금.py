arr = []
def floyd(n, fares):
    global arr

    arr = [[987654321 for _ in range(n)] for _ in range(n)]

    for start, end, weight in fares:
        arr[start - 1][end - 1] = weight
        arr[end - 1][start - 1] = weight

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if arr[i][j] > arr[i][k] + arr[k][j]:
                    arr[i][j] = arr[i][k] + arr[k][j]

    for k in range(n):
        arr[k][k] = 0


def solution(n, s, a, b, fares):
    answer = 987654321
    floyd(n, fares)

    for idx in range(n):
        answer = min(answer, arr[s - 1][idx] + arr[idx][a - 1] + arr[idx][b - 1])

    return answer