#include <iostream>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
queue<int> answer;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v[32001];
int N, M;
int indegree[32001];
void input()
{
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b] ++;
	}
}
void solve()
{
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)
			pq.push(i);

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();
		answer.push(cur);

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			indegree[next]--;
			if (indegree[next] == 0) pq.push(next);
		}

	}
}
void get_answer()
{
	while (!answer.empty())
	{
		cout << answer.front()<<" ";
		answer.pop();
	}
}
int main()
{
	input();
	solve();
	get_answer();
	return 0;
}