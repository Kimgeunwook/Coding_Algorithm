////19:20Ω√¿€
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//#define INF 987654321
//int N, M, X;
//vector<pair<int, int>> v[1001];
//vector<int> dist[1001];
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
//int main()
//{
//	cin >> N >> M >> X;
//	int start, dest, weight;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> start >> dest >> weight;
//		v[start].push_back(make_pair(dest, weight));
//	}
//
//	for (int i = 1; i <= N; i++)
//		dist[i].assign(1000, INF);
//
//
//	for (int k = 1; k <= N; k++)
//	{
//		dist[k][k] = 0;
//		pq.push(make_pair(0, k));
//		
//		while (!pq.empty())
//		{
//			int cur = pq.top().second;
//			int curcost = pq.top().first;
//			pq.pop();
//			
//			for (int i = 0; i < v[cur].size(); i++)
//			{
//				int next = v[cur][i].first;
//				int nextcost = v[cur][i].second;
//				if (dist[k][next] > curcost + nextcost)
//				{
//					dist[k][next] = curcost + nextcost;
//					pq.push(make_pair(dist[k][next], next));
//				}
//			}
//			
//		}
//		
//	}
//	for (int a = 1; a <= 4; a++)
//	{
//		for (int b = 1; b <= 4; b++)
//			cout << dist[a][b] << " ";
//			cout << endl;
//	}
//		
//	int _max = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		_max = max(_max, dist[i][X] + dist[X][i]);
//	}
//		
//	cout << _max << endl;
//	return 0;
//}


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 987654321
int N, M, X;
vector<pair<int, int>> v[1001];
vector<pair<int, int>> rv[1001];
vector<int> dist(1001);
vector<int> rdist(1001);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq, rpq;
int main()
{
	cin >> N >> M >> X;

	int start, dest, weight;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> dest >> weight;
		v[start].push_back(make_pair(dest, weight));
		rv[dest].push_back(make_pair(start, weight));
	}
	fill(dist.begin(), dist.end(), INF);
	fill(rdist.begin(), rdist.end(), INF);

	dist[X] = 0;
	rdist[X] = 0; 
	pq.push(make_pair(0, X));
	rpq.push(make_pair(0, X));
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int curcost = pq.top().first;
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			int nextcost = v[cur][i].second;

			if (dist[next] > curcost + nextcost)
			{
				dist[next] = curcost + nextcost;
				pq.push(make_pair(dist[next], next));
			}

		}
	}
	while (!rpq.empty())
	{
		int cur = rpq.top().second;
		int curcost = rpq.top().first;
		rpq.pop();

		for (int i = 0; i < rv[cur].size(); i++)
		{
			int next = rv[cur][i].first;
			int nextcost = rv[cur][i].second;

			if (rdist[next] > rdist[cur] + nextcost)
			{
				rdist[next] = rdist[cur] + nextcost;
				rpq.push(make_pair(rdist[next], next));
			}

		}
	}

	int _max = 0;
	for (int i = 1; i <= N; i++)
	{
		//if (i == X) continue;
		cout <<dist[i]<<" "<< rdist[i] << endl;
		_max = max(_max, dist[i] + rdist[i]);
	}
	cout << _max << endl;
	return 0;
}