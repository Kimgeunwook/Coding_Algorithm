# 14:55시작
def stage1(s):
    return s.lower()


def stage2(s):
    ret = ""
    for idx in range(len(s)):
        if s[idx].isalpha() or s[idx].isdigit() or s[idx] in ['-', '_', '.']:
            ret = ret + s[idx]
    return ret


def stage3(s):
    while ".." in s:
        s = s.replace("..", ".")
    return s


def stage4(s):
    ret = s
    if ret[0] == '.':
        ret = s[1:]
    if ret != "" and ret[-1] == '.':
        ret = ret[:-1]

    return ret


def stage5(s):
    if s == "":
        return "a"
    else:
        return s


def stage6(s):
    ret = s
    if len(s) >= 16:
        ret = s[0:15]
    if ret[-1] == '.':
        ret = ret[:-1]
    return ret


def stage7(s):
    if len(s) == 1:
        return s + s[0] + s[0]
    elif len(s) == 2:
        return s + s[-1]
    return s


def solution(new_id):
    new_id = stage1(new_id)
    new_id = stage2(new_id)
    new_id = stage3(new_id)
    new_id = stage4(new_id)
    new_id = stage5(new_id)
    new_id = stage6(new_id)
    new_id = stage7(new_id)
    return new_id