import sys
def dfs(_str, _len):
    if len(_str) == _len:
        print(_str)
        sys.exit()

    for idx in range(1,4):
        temp = _str + str(idx)
        flag = 0

        for jdx in range(1,41):
            if len(temp) == 1 or len(temp) < 2 * jdx:
                break
            if temp[-1 * jdx:] == temp[-2 * jdx : -1 * jdx]:
                flag = 1
                break

        if flag == 1:
            continue
        dfs(temp, _len)


N = int(input())
dfs("", N)
