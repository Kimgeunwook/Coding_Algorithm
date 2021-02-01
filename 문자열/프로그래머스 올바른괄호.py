def solution(s):
    answer = True
    arr = []

    flag = True
    for idx in range(len(s)):
        if s[idx] == '(':
            arr.append('(')
            flag = False
        else:
            if len(arr) != 0 and arr[-1] == '(':  # 유효하면
                arr.pop()
            else:
                flag = True
                break

    if flag or len(arr) > 0:
        return False
    else:
        return True