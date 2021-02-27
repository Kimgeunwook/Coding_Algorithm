//풀이방법
//시작점, 주어진 두점에서 다익스트라로 구하기
//min(시작->정점1->정점2->도착점,시작->정점2->정점1->도착점)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
#define INF 987654321

//문제풀이에 필요한 변수
int V_SIZE, E_SIZE, two_point_A, two_point_B;

//다익스트라에 필요한 변수
vector<int> dist(801);
vector<pair<int, int>> v[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

void input()
{
	cin >> V_SIZE >> E_SIZE;

	int start, dest, weight;
	for (int i = 0; i < E_SIZE; i++)
	{
		cin >> start >> dest >> weight;
		v[start].push_back(make_pair(dest, weight)); //start에서 dest까지 weight이다 == v[start] = {dest,weight}
		v[dest].push_back(make_pair(start, weight));
	}

	cin >> two_point_A >> two_point_B;
}

long long dijkstra(int start, int end)
{
	fill(dist.begin(), dist.end(), INF);

	dist[start] = 0;
	pq.push(make_pair(0, start));//(cost, 목적지)순 (cost순 오름차순 위해)

	while (!pq.empty())
	{
		int cur = pq.top().second;

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
	return dist[end];
}

int main()
{
	input();
	//출발점 -> A -> B -> 도착점 VS 출발점 -> B -> A -> 도착점
	long long answer = min(dijkstra(1, two_point_A) + dijkstra(two_point_A, two_point_B) + dijkstra(two_point_B, V_SIZE),
		dijkstra(1, two_point_B) + dijkstra(two_point_B, two_point_A) + dijkstra(two_point_A, V_SIZE));
	if (answer >= INF)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << answer << endl;
	return 0;
}
