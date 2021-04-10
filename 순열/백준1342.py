s = input()
arr = []
_set = set()
temp = ['a' for _ in range(10)]
visit = [False for _ in range(10)]
answer = 0
for idx in range(len(s)):
    arr.append(s[idx])

def solve():
    for idx in range(len(arr) - 1):
        cur = temp[idx]
        if cur == temp[idx + 1]:
            return False

    return True

def comb(cnt):
    global answer
    if cnt == len(arr):
        if solve():
            #print("".join(temp))
            _set.add("".join(temp))
            answer = answer + 1
    else:
        for idx in range(len(arr)):
            if visit[idx] == False:
                visit[idx] = True
                temp[cnt] = arr[idx]
                comb(cnt + 1)
                visit[idx] = False


comb(0)
print(len(_set))