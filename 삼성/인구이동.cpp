#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int N, L, R;
int answer = 0, _cnt = 0;
int map[50][50];
int visit[50][50];
queue<pair<int, int>> v;
vector<pair<int, int>> v_cur;
void dfs(int i, int j)
{
	v_cur.push_back(make_pair(i, j));
	int country = 0, mount = 0;
	visit[i][j] = 1;
	int cur_x, cur_y;
	while (!v.empty())
	{
		country += 1;
		cur_x = v.front().first;
		cur_y = v.front().second;
		v.pop();
		mount += map[cur_x][cur_y];

		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				if (!(i == 0 && j == 0) && i * j == 0)
					if (cur_x + i >= 0 && cur_x + i < N && cur_y + j >= 0&& cur_y + j < N)
						if (visit[cur_x + i][cur_y + j] == 0 && L <= abs(map[cur_x][cur_y] - map[cur_x + i][cur_y + j]) && abs(map[cur_x][cur_y] - map[cur_x + i][cur_y + j]) <= R)
						{
							visit[cur_x + i][cur_y + j] = 1;
							v.push(make_pair(cur_x + i, cur_y + j));
							v_cur.push_back(make_pair(cur_x + i, cur_y + j));
						}

	}
	if (country >= 2)
		_cnt += 1;
	for (int i = 0; i < v_cur.size(); i++)
		map[v_cur[i].first][v_cur[i].second] = mount/country;

}
int main()
{
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
		
	while (1)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visit[i][j] = 0;
		_cnt = 0;
		for (int i = 0; i < N ; i++)
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j] == 1)
					continue;
				while (!v.empty())
				{
					v.pop();
				}
				v.push(make_pair(i, j));
				v_cur.clear();
				dfs(i, j);
			}
		if (_cnt == 0)
			break;
		else
			answer += 1;
	}
	cout << answer << endl;
	return 0;
}
