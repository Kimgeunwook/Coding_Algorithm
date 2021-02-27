# 16:52시작
from itertools import combinations
answer = []
def solve(orders, n):
    global answer
    dic = {}
    for order_item in orders:  # ABCFG -> AC -> CDE -> ...
        comb_list = list(combinations(order_item, n))
        for item in comb_list:  # (A,B) -> (A,C) -> (A,F) -> ...
            a = list(item)
            a.sort()
            join_item = "".join(a)
            if join_item in dic:
                dic[join_item] = dic[join_item] + 1
            else:
                dic[join_item] = 1
    max_cnt = -1
    max_item = []
    for key, value in dic.items():
        if value > max_cnt and value > 1:
            max_item = []
            max_cnt = value
            max_item.append(key)
        elif value == max_cnt:
            max_item.append(key)

    answer = answer + max_item


def solution(orders, course):
    for num in course:
        solve(orders, num)
    global answer
    answer.sort()
    return answer