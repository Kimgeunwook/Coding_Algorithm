_cnt = 0
original_words_list = []
visit = []
_min = 987654321


def one_compare(x, y, length):
    dif_cnt = 0
    for i in range(length):
        if (x[i] != y[i]):
            dif_cnt += 1
    if dif_cnt == 1:
        return True  # 한글자만 틀리면true
    else:
        return False


def solution(begin, target, words):
    global _cnt, original_words_list, _min, visit
    answer = 0
    one_dif_list = []  # 한개만 다른애들 모음

    for i in words:  # words다 돌면서
        if one_compare(begin, i, len(begin)):  # 한개 차이나는건 추가하려는데
            print(begin + ' ' + i + ' ' + str(_cnt))

            if (begin, i) not in visit and (i, begin) not in visit:  # 이미 있는거면 추가 하지 않기
                visit.append((begin, i))
                print(visit)
                one_dif_list.append(i)
            if target in one_dif_list:  # 한 번 거쳐서 바꿀수 있으면
                return _cnt + 1  # 현재 _cnt값+1 을 return

    _cnt += 1
    for i in one_dif_list:
        _min = min(solution(i, target, words), _min)  # set만들어서 반복피하기
        print(i + ' ' + target + ' ' + str(_min) + '이다')
    _cnt -= 1
    if _min == 987654321:
        return 0
    return _min