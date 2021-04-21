//1125Ω√¿€
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, answer;
vector<int> v, dp;

void input()
{
	cin >> N;
	for(int i = 0 ; i < N; i++)
	{
		int a; cin >> a;
		v.push_back(a);
	}
}

void solve()
{
	dp.push_back(v[0]);
	for (int i = 1; i < N; i++)
	{
		if (v[i] > dp[dp.size() - 1]) dp.push_back(v[i]);
		else
		{
			int idx = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
			dp[idx] = v[i];
		}
	}
	answer = dp.size();

	/*dp.clear();

	for (int i = 0; i < N; i++) v[i] *= -1;
	dp.push_back(v[N - 1]);
	for (int i = N - 2; i >= 0; i--)
	{
		if (v[i] > dp[dp.size() - 1]) dp.push_back(v[i]);
		else
		{
			int idx = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
			dp[idx] = v[i];
		}
	}
	cout << dp.size() << endl;
	answer = max(answer, (int)dp.size());*/
}
int main()
{
	input();
	solve();
	cout << N - answer << endl;
	return 0;
}