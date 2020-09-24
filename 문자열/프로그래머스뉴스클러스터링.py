# 1519시작
def solution(str1, str2):
    answer = 0
    arr1 = []
    arr2 = []

    if len(str1) >= 2:
        for idx in range(len(str1) - 1):
            temp = str1[idx:idx + 2].upper()
            if 'A' <= temp[0] and temp[0] <= 'Z' and 'A' <= temp[1] and temp[1] <= 'Z':
                arr1.append(temp)
    if len(str2) >= 2:
        for idx in range(len(str2) - 1):
            temp = str2[idx:idx + 2].upper()
            if 'A' <= temp[0] and temp[0] <= 'Z' and 'A' <= temp[1] and temp[1] <= 'Z':
                arr2.append(temp)

    len1 = len(arr1)
    len2 = len(arr2)

    visit = [0 for _ in range(len2)]
    kyo = 0

    for i in arr1:
        for j in range(len2):
            if i == arr2[j] and visit[j] == 0:
                visit[j] = 1
                kyo += 1
                break

    if len1 == 0 and len2 == 0:
        return 65536
    print(kyo, len1, len2)
    answer = 65536 * (kyo / (len1 + len2 - kyo))
    answer = answer // 1
    return answer