#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int dist[10001];
vector<pair<int, int>> arr[10001];
queue<pair<int, int>> q;
int n, d, start, cnt = 1;

void init()
{
	for (int i = 1; i <= n; i++)
	{
		arr[i].clear();
		dist[i] = 0;
	}
	cnt = 1;
}
void input()
{
	cin >> n >> d >> start;
	int a, b, c;
	for (int i = 0; i < d; i++)
	{
		cin >> a >> b >> c;
		arr[b].push_back({ a,c });
	}
}

void solve()
{
	q.push({ start, 0 });
	while (!q.empty())
	{
		int cur = q.front().first;
		int depth = q.front().second;
		q.pop();
		for (int i = 0; i < arr[cur].size(); i++)
		{
			int next = arr[cur][i].first;
			int next_depth = arr[cur][i].second;

			if (next != start)
			{
				if (dist[next] == 0)
				{
					cnt++;
					dist[next] = depth + next_depth; //ù �湮case
				}
				else if (depth + next_depth < dist[next]) dist[next] = depth + next_depth;
				else continue;

				q.push({ next, dist[next] });
			}

		}
	}
}

int get_answer()
{
	int ret = 0;
	for (int i = 1; i <= n; i++)
		if (ret < dist[i]) ret = dist[i];

	return ret;
}
int main()
{
	int N; cin >> N;
	while (N--)
	{
		input();
		solve();
		cout << cnt << " " << get_answer() << endl;
		init();
	}
	return 0;
}