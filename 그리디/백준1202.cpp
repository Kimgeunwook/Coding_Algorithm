//1844Ω√¿€
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>
int N, K, M, V;
long long ans = 0;
vector<pair<int, int>> v;
vector<int> bag;
priority_queue<int> pq;
void input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> M >> V;
		v.push_back(make_pair(M, V));
	}
	for (int i = 0; i < K; i++)
	{
		int a; cin >> a;
		bag.push_back(a);
	}
	sort(v.begin(), v.end());
	sort(bag.begin(), bag.end());
	
}
void solve()
{
	int k = 0;
	for (int i = 0; i < bag.size(); i++)
	{
		for (int j = k; j < v.size(); j++)
		{
			if (v[j].first <= bag[i])
			{
				pq.push(v[j].second);
				k++;
			}
			else
			{
				break;
			}
		}
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
}
int main()
{
	input();
	solve();
	cout << ans << endl;
}