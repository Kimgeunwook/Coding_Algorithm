from _collections import deque


def solution(cacheSize, cities):
    answer = 0
    dq = deque()
    if cacheSize == 0:
        return 5 * len(cities)

    for i in cities:
        flag = 0
        idx = -1
        for j in range(len(dq)):
            if i.upper() == dq[j].upper():
                flag = 1
                idx = j
                break

        if flag == 0:
            answer += 5
        else:
            answer += 1

        if flag != 0:
            del dq[idx]
            dq.append(i)
        else:
            if len(dq) == cacheSize:
                dq.popleft()
            dq.append(i)

    return answer