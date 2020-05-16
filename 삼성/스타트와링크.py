from itertools import combinations
import sys
N = int(input())
all = [i for i in range(N)]
_MAP = [list(map(int,input().split())) for _ in range(N)]
_min = sys.maxsize
visit = set()
team_start = list(combinations(all,int(N/2)))
for t_s in range (len(team_start)): #team_start = [(0, 1), (0, 2), (0, 3), (1, 2), (1, 3), (2, 3)]
    sort_list = sorted(team_start[t_s])
    if tuple(sort_list) in visit:
        continue
    visit.add(tuple(sort_list))
    team_link = []
    for t_s_idx in range(N):
        if not t_s_idx in team_start[t_s]:
            team_link.append(t_s_idx)
    visit.add(tuple(sorted(team_link)))
    team_start_score = 0
    team_link_score = 0
    for s_i_1 in range(len(team_start[t_s])):
        for s_i_2 in range(len(team_start[t_s])):
            if s_i_1 != s_i_2:
                team_start_score += _MAP[team_start[t_s][s_i_1]][team_start[t_s][s_i_2]]
                team_link_score += _MAP[team_link[s_i_1]][team_link[s_i_2]]
    if abs(team_link_score - team_start_score) < _min:
        _min = abs(team_link_score - team_start_score)

print(_min)


