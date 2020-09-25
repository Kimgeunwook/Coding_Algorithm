# 9:44시작 #10:05끝
def solution(record):
    answer = []
    temp = []
    dic = {}
    for i in record:
        keyword = i.split()[0]
        _id = i.split()[1]

        if keyword == 'Enter':
            name = i.split()[2]
            dic[_id] = name
            temp.append((_id, keyword))
        elif keyword == 'Leave':
            temp.append((_id, keyword))
        elif keyword == 'Change':
            name = i.split()[2]
            dic[_id] = name

    for i in temp:
        key = i[1]
        _id = i[0]
        if key == 'Enter':
            str = dic[_id] + '님이 들어왔습니다.'
            answer.append(str)
        elif key == 'Leave':
            str = dic[_id] + '님이 나갔습니다.'
            answer.append(str)

    return answer