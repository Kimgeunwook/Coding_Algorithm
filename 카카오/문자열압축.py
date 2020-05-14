def compression(s, num):
    answer = len(s)
    i = 0
    while i < len(s):
        continous_cnt = 0
        dif_flag = 0

        if i > len(s) - 2 * num:  # 진행하는 단위의 2배 여유가 없으면 굳이 할 필요가 없다.
            break

        for j in range((len(s) - i) // num):  # 최대 (len(s0-i)//num 번 할 수 있다.
            for k in range(num):
                if s[i + k] != s[i + k + num * (j)]:  # num만큼 비교하는데 하나라도 다르면 바로 flag걸고 break
                    dif_flag = 1
                    break
            if dif_flag == 1:
                break
            else:  # 다 같으면
                continous_cnt = continous_cnt + 1

        if continous_cnt != 1:
            answer = answer + len(str(continous_cnt)) + num - continous_cnt * num
        i = i + continous_cnt * num
    return answer


def solution(s):
    answer = 987654321
    for i in range(len(s)):
        if (compression(s, i + 1) < answer):
            answer = compression(s, i + 1)
    return answer
