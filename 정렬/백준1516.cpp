#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int>v[501];
queue<int> q;
int degree[501], cost[501], ans[501];
int N;
void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		ans[i] = cost[i] = n;
		while (1)
		{
			cin >> n;
			if (n == -1) break;
			v[n].push_back(i);
			degree[i]++;
		}
		if (degree[i] == 0) q.push(i);
	}	

}
void Solve()
{
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			ans[v[cur][i]] = max(ans[v[cur][i]], ans[cur] + cost[v[cur][i]]);
			degree[v[cur][i]]--;
			if (degree[v[cur][i]] == 0) q.push(v[cur][i]);
		}
	}
}
void GetAns()
{
	for (int i = 1; i <= N; i++)
		cout << ans[i] << endl;
}
int main(){
	Input();
	Solve();
	GetAns();
}