#참고
# https://dev-note-97.tistory.com/131
from itertools import combinations

dic = {}
answer = []
def make_dic(info):
    for item in info:
        itemarr = item.split(" ")  # [java, backend, junior, pizza, 150]
        for n in range(0, 5):
            arr = list(combinations(range(4), n))  # (0,) , .... (0,1,3) 전부 다

            for arritem in arr:  # arr = [(0,), (1,), (2,), (3,)]
                str = ""
                for idx in range(4):
                    if idx in arritem:
                        str = str + "-"
                    else:
                        str = str + itemarr[idx]

                if str in dic:
                    dic[str].append(int(itemarr[-1]))
                else:
                    dic[str] = [int(itemarr[-1])]


def lowerBound(query_str, score):
    start = 0
    end = len(dic[query_str])
    length = end
    while start < end:
        mid = (start + end) // 2
        if dic[query_str][mid] < score:
            start = mid + 1
        else:
            end = mid

    return length - end


def solve(query):
    for item in query:
        arr = item.split(' ')[:-1]
        score = int(item.split(' ')[-1])
        arr = [x for x in arr if x != 'and']
        query_str = "".join(arr)
        if query_str in dic:
            answer.append(lowerBound(query_str, score))
        else:
            answer.append(0)


def solution(info, query):
    make_dic(info);
    for value in dic.values():  # 딕셔너리 내 모든 값 정렬
        value.sort()
    solve(query)

    return answer