arr = [0 for _ in range(360001)]
prefixsum = [0 for _ in range(360001)]


def time_to_seconds(time):
    ret = 0
    ret = ret + int(time[0:2]) * 3600 + int(time[3:5]) * 60 + int(time[6:])
    return ret


def seconds_to_time(seconds):
    m, s = divmod(seconds, 60)
    h, m = divmod(m, 60)
    return f'{h:02d}:{m:02d}:{s:02d}'


def prefix_sum(logs):
    global arr, prefixsum
    for item in logs: #in and out
        start = time_to_seconds(item[0:8])
        end = time_to_seconds(item[9:])
        arr[start] = arr[start] + 1
        arr[end] = arr[end] - 1

    for idx in range(1, 360001): #구간별 재생 수 구하기
        arr[idx] = arr[idx - 1] + arr[idx]

    sum = 0
    for idx in range(360001): # 누적 재생 수 구하기
        sum = sum + arr[idx]
        prefixsum[idx] = sum


def solve(play_time, adc_time):
    global prefixsum
    play_time = time_to_seconds(play_time)
    adc_time = time_to_seconds(adc_time)
    max_people = -1
    max_point = -1
    for idx in range(len(prefixsum)):
        if idx + adc_time > play_time:
            break
        if prefixsum[idx + adc_time] - prefixsum[idx] > max_people:
            max_people = prefixsum[idx + adc_time] - prefixsum[idx]
            max_point = idx
    if max_point != 0:
        return seconds_to_time(max_point + 1)
    return seconds_to_time(max_point)


def solution(play_time, adv_time, logs):
    answer = ''
    prefix_sum(logs)
    answer = solve(play_time, adv_time)
    return answer