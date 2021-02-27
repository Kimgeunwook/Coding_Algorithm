//12:41시작
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 1000000000
int N, M, A, B, C, factory_A, factory_B;
int s = 1, e, mid;
int Max_Cost = 0;
int answer;
vector< pair<int, int>> v[10001];
bool visit[100001];
queue<int> q;
void bfs(int mid)
{
	for (int i = 1; i <= 100000; i++)
		visit[i] = false;

	visit[factory_A] = true;
	q.push(factory_A);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			if (v[cur][i].second >= mid && visit[v[cur][i].first] == false)
			{
				q.push(v[cur][i].first);
				visit[v[cur][i].first] = true;
			}

		}


	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		v[A].push_back({ B, C });
		v[B].push_back({ A, C });
		Max_Cost = max(Max_Cost, C);
	}
	cin >> factory_A >> factory_B;
	e = Max_Cost;
	while (s <= e)
	{
		mid = (s + e) / 2;
		bfs(mid);
		if (visit[factory_B])// 최대치 mid로 했을때 길이 있으면
		{
			answer = max(answer, mid);
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
	}

	cout << answer << endl;
	return 0;
}