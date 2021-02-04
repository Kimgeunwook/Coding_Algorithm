//1. �� ���� Ǯ���� �ٽ��� ���ͽ��󿡼� �ּҰ� ���� ���ٶ� indegree�� ���� ���ִ°�
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define INF 987654321

int N, E_size, Start, End;
vector<int> dist(1001), indegree(1001);
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
vector<int> s_to_e_route;
void input()
{
	cin >> N;
	cin >> E_size;
	int s, e, weight;
	for (int i = 0; i < E_size; i++)
	{
		cin >> s >> e >> weight;
		v[s].push_back(make_pair(e, weight)); //start���� dest���� weight�̴� 
	}
	cin >> Start >> End;

}

int dijkstra(int start, int end)
{
	fill(dist.begin(), dist.end(), INF);

	dist[start] = 0;
	pq.push(make_pair(0, start));//(cost, ������)�� (cost�� �������� ����)

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
				//���Ⱑ �ٽ� next���� ���µ� ���� �ֱٿ� �湮�ߴ� vertex�� ����س���
				indegree[next] = cur;
			}

		}
	}
	return dist[end];
}

int get_Vsize(int start, int end)
{
	int cnt = 2;
	int cur = end;
	while (1)
	{
		if (indegree[cur] == start) return cnt;
		cur = indegree[cur];
		s_to_e_route.push_back(cur);
		cnt++;
	}
}
int main()
{
	input();
	cout << dijkstra(Start, End) << endl;

	s_to_e_route.push_back(End);
	cout << get_Vsize(Start, End) << endl;
	s_to_e_route.push_back(Start);
	for (int i = s_to_e_route.size() - 1; i >= 0; i--)
		cout << s_to_e_route[i] << " ";

	
	cout << endl;
	return 0;
}