def solution(genres, plays):
    answer = []
    dict = {}
    for i in range(len(genres)):
        dict[genres[i]] = dict.get(genres[i], 0) + plays[i]

    sdict = sorted(dict.items(), reverse=True, key=lambda item: item[1])

    for i in range(len(sdict)):
        lists = []
        _cnt = 0
        for j in range(len(plays)):
            if sdict[i][0] == genres[j]:
                lists.append((j, plays[j]))
        lists.sort(key=lambda t: (-t[1], t[0]))

        for k in lists:
            if _cnt < 2:
                answer.append(k[0])
                _cnt += 1
            else:
                break

    return answer
