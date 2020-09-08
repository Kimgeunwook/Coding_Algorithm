
def solution(n):
    answer = [0 for i in range(pow(2,n) - 1)]
    for i in range(2, n + 1): #n만큼 반복
        interval = int( (pow(2,n) - 1) / pow(2, i - 1)) - int( (pow(2,n) - 1) / pow(2, i))
        answer[int( (pow(2,n) - 1) / pow(2, i))] = 0
        for j in range(1, pow(2,i - 1)): #자기는 체크해주고 대칭쪽도 지그재그로 조지기
            if (j % 2 == 1):
                answer[2 * j * interval + int( (pow(2,n) - 1) / pow(2, i))] = 1
            else :
                answer[2 * j * interval + int( (pow(2,n) - 1) / pow(2, i))] = 0
    return answer


print(solution(3))
