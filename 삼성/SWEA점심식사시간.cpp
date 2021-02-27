//0802시작
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
int N, _max,_min;
int map[10][10];
vector<pair<int, int>> people;
int temp[10];
pair<int, int> stair[2];
int stairsize[2];
priority_queue<int, vector<int>, greater<int>> pq_ready[2], pq_running[2];
void input()
{
	cin >> N;
	people.clear();
	int flag = true;
	for(int i = 0; i < N ;i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				people.push_back({ i,j });
			}
			else if (map[i][j] > 1)
			{
				if (flag)
				{
					stair[0] = { i,j };
					stairsize[0] = map[i][j];
					flag = false;
				}
				else
				{
					stair[1] = { i,j };
					stairsize[1] = map[i][j];
				}
			}
		}
	//변수초기화
	_max = 0;
	_min = 987654321;
	
}
void stairSet()
{
	for (int i = 0; i < people.size(); i++)
	{
		if (temp[i] == 0)
		{
			int dist = abs(people[i].first - stair[0].first) + abs(people[i].second - stair[0].second);
			pq_ready[0].push(dist + 1);
		}
		else if (temp[i] == 1)
		{
			int dist = abs(people[i].first - stair[1].first) + abs(people[i].second - stair[1].second);
			pq_ready[1].push(dist + 1);
		}
	}
}
void solve()
{
	_max = 0;
	for (int k = 0; k < 2; k++)
	{
		int time = 0;
		while (!pq_ready[k].empty())
		{
			//계단 다내려간애 있는지 확인
			while (!pq_running[k].empty())
			{
				int cur = pq_running[k].top();
				if (cur + stairsize[k] > time) break;
				else pq_running[k].pop();
			}

			//계단에 진입할애 있는지 확인
			while (pq_running[k].size() < 3)
			{
				if (!pq_ready[k].empty())
				{
					int cur = pq_ready[k].top();
					if (cur > time) break;
					else
					{
						//cout << time << "초에" << endl;
						pq_running[k].push(time);
						pq_ready[k].pop();
					}
				}
				else break;
			}
			time++;
		}
		//cout << endl;
		//pq_running에서 남은거 빼고 최대시간 계산
		while (!pq_running[k].empty())
			pq_running[k].pop();
		if (_max < time - 1 + stairsize[k]) _max = time - 1 + stairsize[k];
		//cout << "max:" << _max << endl;
	}
	for (int i = 0; i < people.size(); i++)
		cout << temp[i] << " ";
	cout << endl;
	cout << _max << endl;
	if (_max < _min) _min = _max;
}
void dfs(int cnt)
{
	/*temp[0] = 0;
	temp[1] = 0;
	temp[2] = 0;
	temp[3] = 1;
	temp[4] = 1;
	temp[5] = 1;
	stairSet();
	solve();*/
	if (cnt == people.size())
	{
		stairSet();
		solve();
	}
	else
	{
		for (int i = cnt; i < people.size(); i++)
		{
			for (int j = 0; j < 2; j++)
			{
				temp[i] = j;
				dfs(i + 1);
			}
		}
	}
}
int main()
{
	int T; cin >> T;
	for (int i = 1; i <= T; i++)
	{
		input();
		dfs(0);
		cout << "#" << i << " " << _min << endl;
	}
	return 0;
}