#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;
int N, answer;
priority_queue<int> pq;
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		v.push_back({ b, -a });
	}
	
}

void solve()
{
	for (int i = 0; i < v.size(); i++)
	{
		int curday = v[i].first;
		int cost = -v[i].second;
		
		pq.push(-cost);

		if (pq.size() > curday) pq.pop();
	}
}
void get_answer()
{
	while (!pq.empty())
	{
		answer += pq.top();
		pq.pop();
	}
}
int main()
{
	input();
	sort(v.begin(), v.end());
	solve();
	get_answer();
	cout << -answer << endl;
	return 0;
}