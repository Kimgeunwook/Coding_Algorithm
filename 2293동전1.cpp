#include <iostream>
using namespace std;
int num[101], dp[10001], n, k;
int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> num[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = num[i]; j <= k; j++)
		{
			if (j == num[i])
				dp[j] = dp[j] + 1;
			else
				dp[j] = dp[j] + dp[j - num[i]];
		}
	}
	cout << dp[k];
	return 0;
}