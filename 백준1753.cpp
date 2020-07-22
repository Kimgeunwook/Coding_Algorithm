//20시 시작
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define SIZE 20001
using namespace std;
int V, E, N;
vector<int> dist(SIZE);
vector<pair<int, int>> v[SIZE];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
int main()
{
	cin >> V >> E;
	cin >> N;
	int start, dest, weight;
	for (int i = 0; i < E; i++)
	{
		cin >> start >> dest >> weight;
		v[start].push_back(make_pair(dest, weight)); //start에서 dest까지 weight이다 == v[start] = {dest,weight}
	}

	fill(dist.begin(), dist.end(), INF);

	dist[N] = 0;
	pq.push(make_pair(0, N)); //(cost, 목적지)순 (cost순 오름차순 위해)

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cur_cost = pq.top().first;
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			int nextcost = v[cur][i].second;

			if (dist[next] > dist[cur] + nextcost)
			{
				dist[next] = dist[cur] + nextcost;
				pq.push(make_pair(dist[next], next));
			}

		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}

}