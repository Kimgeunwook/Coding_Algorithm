# 2100 시작
# 2205 끝

# 문자열에 ? 를 chr로 바꿔주는 함수
def convert(str, chr):
    tmp = ""
    for idx in range(len(str)):
        if str[idx] == '?':
            tmp = tmp + chr
        else:
            tmp = tmp + str[idx]
    return tmp


def upper_bound(arr, key):
    start = 0
    end = len(arr)
    while start < end:
        mid = (start + end) // 2
        if len(arr[mid]) > len(key):
            end = mid
        elif len(arr[mid]) == len(key):
            if arr[mid] <= key:
                start = mid + 1
            else:
                end = mid
        else:
            start = mid + 1

    return end


def lower_bound(arr, key):
    start = 0
    end = len(arr)
    while start < end:

        mid = (start + end) // 2

        if len(arr[mid]) > len(key):
            end = mid
        elif len(arr[mid]) == len(key):
            if arr[mid] >= key:
                end = mid
            else:
                start = mid + 1
        else:
            start = mid + 1

    return end


def solve(sorted_arr, r_sorted_arr, queries):
    global answer
    for item in queries:
        if item[-1] == '?':  # 정방향
            answer.append(upper_bound(sorted_arr, convert(item, 'z')) - lower_bound(sorted_arr, convert(item, 'a')))
        else:  # 역방향
            answer.append(upper_bound(r_sorted_arr, convert(item, 'z')[::-1]) - lower_bound(r_sorted_arr,
                                                                                            convert(item, 'a')[::-1]))


def solution(words, queries):
    global answer
    answer = []
    arr_set = set(words)
    arr = list(arr_set)  # words 중복 제거한 리스트

    sorted_arr = sorted(arr, key=lambda x: (len(x), x))
    r_sorted_arr = sorted(list(map(lambda x: x[::-1], arr)), key=lambda x: (len(x), x))

    solve(sorted_arr, r_sorted_arr, queries)
    return answer