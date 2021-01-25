def solution(s):
    answer = ''

    flag = True
    for idx in range(len(s)):
        if s[idx] == ' ':
            flag = True
            answer = answer + ' '
        elif flag:
            flag = False
            answer = answer + s[idx].upper()
        else:
            flag = False
            answer = answer + s[idx].lower()

    return answer