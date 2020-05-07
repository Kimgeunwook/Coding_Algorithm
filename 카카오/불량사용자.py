from itertools import permutations
def matching(stringA,stringB):
    if len(stringA) != len(stringB):
        return False
    for i in range(len(stringB)):
        if stringB[i] == '*':
            continue
        elif stringA[i] != stringB[i]:
            return False
    return True

def solution(user_id, banned_id):
    answer = []
    for i in list(permutations(user_id,len(banned_id))):
        name_list=[]
        _set = []
        for j in range(len(i)):
            for k in range(len(banned_id)):
                if matching(i[j], banned_id[k]) and k not in _set:
                    name_list.append(i[j])
                    _set.append(k)
                    break
        if len(_set) == len(banned_id) and sorted(name_list) not in answer :
            answer.append(sorted(name_list))

    return len(answer)

print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],["fr*d*", "abc1**"]))


