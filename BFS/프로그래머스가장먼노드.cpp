<<<<<<< Updated upstream:BFS/프로그래머스가장먼노드.cpp
//1520½ÃÀÛ
=======
//1520���� //1542��
>>>>>>> Stashed changes:프로그래머스가장먼노드.cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
struct info {
	int x, depth;
};
vector<int> v[20001];
vector<int> dist(20001);
int visit[20001];
queue<info> q;
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	for (int i = 0; i < edge.size(); i++)
	{
		v[edge[i][0]].push_back(edge[i][1]);
		v[edge[i][1]].push_back(edge[i][0]);
	}
	q.push({1, 0});
	visit[1] = 1;
	while (!q.empty())
	{

		info cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur.x].size(); i++)
		{
			if (visit[v[cur.x][i]] == 0) // ¹æ¹®ÇÑ°÷ÀÌ ¾Æ´Ï¸é
			{
				visit[v[cur.x][i]] = 1;
				info newbie = { v[cur.x][i]  , cur.depth + 1};
				q.push(newbie);
				dist[v[cur.x][i]] = cur.depth + 1;
			}
		}
	}

	sort(dist.begin(), dist.end(), greater<int>());
	for (int i = 0; i < n; i++)
		if (dist[0] == dist[i]) answer++;
	return answer;
}

int main()
{
	cout << solution(6, {{3, 6}, { 4, 3 }, { 3, 2 }, { 1, 3 }, { 1, 2 }, { 2, 4 }, { 5, 2 }}) << endl;
	return 0;
}
