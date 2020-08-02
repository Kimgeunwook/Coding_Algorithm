#include <iostream>
using namespace std;
int dp[1001];
int main()
{
	int a = 1;
	for (int i = 1; i <= 45; i++)
		for (int j = 1; j <= i; j++)
		{
			dp[a] = dp[a - 1] + i;
			a++;
		}

	int k, p;
	cin >> k >> p;
	cout << dp[p] - dp[k - 1];
	return 0;
}