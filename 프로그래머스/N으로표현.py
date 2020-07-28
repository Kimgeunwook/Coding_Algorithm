def solution(N, number):
    answer = 0
    s=[set() for i in range(8)]
    for index,i in enumerate(s,start=1):
        i.add(int(str(N)*index))

    for k in range(2,9):
        for i in range(0,k-1):
            for x in s[i]:
                for y in s[k-i-2]:
                    s[k-1].add(x+y)
                    s[k-1].add(x - y)
                    s[k-1].add(x * y)
                    if(y!=0):
                        s[k-1].add(x / y)

        if number in s[k-1]:
            answer=k
            break
    if answer==0:
        return -1
    return answer
