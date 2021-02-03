//Ǯ�̹��
//������, �־��� �������� ���ͽ�Ʈ��� ���ϱ�
//min(����->����1->����2->������,����->����2->����1->������)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
#define INF 987654321

//����Ǯ�̿� �ʿ��� ����
int V_SIZE, E_SIZE, two_point_A, two_point_B;

//���ͽ�Ʈ�� �ʿ��� ����
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
		v[start].push_back(make_pair(dest, weight)); //start���� dest���� weight�̴� == v[start] = {dest,weight}
		v[dest].push_back(make_pair(start, weight));
	}

	cin >> two_point_A >> two_point_B;
}

long long dijkstra(int start, int end)
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
			}

		}
	}
	return dist[end];
}

int main()
{
	input();
	//����� -> A -> B -> ������ VS ����� -> B -> A -> ������
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