#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int dp[1000001];
vector<int> v;
int main()
{
	vector<int>::iterator it;
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> dp[i];
	v.push_back(-1);
	for (int i = 1; i <= num; i++)
	{
		if (dp[i] > v.back())
			v.push_back(dp[i]);
		else
		{
			it = lower_bound(v.begin(), v.end(), dp[i]);
			v[it - v.begin()] = dp[i];
		}
	}
	cout << v.size() - 1;
	return 0;
}