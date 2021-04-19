#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[1001];
int indegree[1001];
pair<int,int> max_order[1001];
int K, M, P, answer;
queue<int> q;
void init()
{
	answer = 0;
	for (int i = 0; i <= M; i++)
	{
		v[i].clear();
		indegree[i] = 0;
		max_order[i] = { 0, 0 };
	}
}

void input()
{
	int a, b;
	for (int i = 0; i < P; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
}

void find_starting_point()
{
	for(int i = 1; i <= M ;i++)
		if (!indegree[i])
		{
			q.push(i);
			max_order[i] = { 1, 1 };
		}
}

void solve()
{
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			if (max_order[next].first < max_order[cur].first)
			{
				
				max_order[next].first = max_order[cur].first;
				max_order[next].second = 1;
			}
			else if (max_order[next].first == max_order[cur].first)
			{
				max_order[next].second++;
			}

			if (--indegree[next] == 0)
			{
				if (max_order[next].second >= 2)
				{
					answer = max(answer, max_order[next].first + 1);
					max_order[next].first++;
				}
				else answer = max(answer, max_order[next].first);

				q.push(next);
			}

		}
	}
}
int main()
{
	int T; cin >> T;
	while (T--)
	{
		cin >> K >> M >> P;
		init();
		input();
		find_starting_point();
		solve();
		cout << K << " " << max_order[M].first << endl;
	}
	return 0;
}