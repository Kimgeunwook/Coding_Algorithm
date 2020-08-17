//1418½ÃÀÛ
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct info {
	int start, des, val;
};
struct comp {
	bool operator()(info a, info b)
	{
		return a.val > b.val;
	}
};
int parent[101];
int _find(int n)
{
	if (parent[n] == n) return n;
	else return parent[n] = _find(parent[n]);
}

void _Union(int a, int b)
{
	int i = _find(a);
	int j = _find(b);
	parent[i] = j;
}
priority_queue<info, vector<info>, comp> pq;
bool visit[101];
int solution(int n, vector<vector<int>> costs) {
	
	int answer = 0;
	for (int i = 0; i < costs.size(); i++) pq.push({ costs[i][0], costs[i][1], costs[i][2] });
	while (!pq.empty())
	{
		info cur = pq.top();
		pq.pop();
		if (_find(cur.start) == _find(cur.des)) continue;

		_Union(cur.start, cur.des);
		answer += cur.val;
	}
	return answer;
}
int main()
{
	for (int i = 0; i <= 100; i++)
		parent[i] = i;
	cout << solution(4, { {2, 3, 3},{2, 4, 4},{3, 4, 7},{3, 5, 3},{4, 5, 10} }) << endl;
	return 0;
}
