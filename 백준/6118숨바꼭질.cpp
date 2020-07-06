#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include<algorithm>
#include<functional>
int dist[20001];
bool visit_real[20001];
vector<int> dp[20001];

int main()
{

	int N, M;
	int a, b;
	int v;
	cin >> N >> M;
	queue<int> visit;
	vector<int>::iterator iter;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		dp[a].push_back(b);
		dp[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		dist[i] = 99999;

	dist[1] = 0;
	v = 1;
	visit_real[1] = true;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j != dp[v].size(); j++)
		{
			if (!visit_real[dp[v][j]])
			{
				visit.push(dp[v][j]);
				visit_real[dp[v][j]] = true;
			}
			if (dist[dp[v][j]] > dist[v] + 1)
				dist[dp[v][j]] = dist[v] + 1;
		}
		if (!visit.empty())
		{
			v = visit.front();
			visit.pop();
		}
	}
	int max = -100;
	int count = 0;
	int index;
	for (int i = 2; i <= N; i++)
	{
		if (dist[i] > max)
		{
			max = dist[i];
			count = 1;
			index = i;
		}
		else if (dist[i] == max)
			count++;
	}

	cout << index << " " << max << " " << count << endl;

	return 0;
}