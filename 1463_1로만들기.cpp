#include <iostream>
using namespace std;
#include <algorithm>
int dp[1000001];
int main()
{
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		if (i == 1)
			dp[1] = 0;
		else
		{
			if ((i % 3 == 0) && (i % 2 == 0))
				dp[i] = min(min(dp[i / 3] + 1, dp[i / 2] + 1), dp[i - 1] + 1);
			else if (i % 3 == 0)
				dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
			else if (i % 2 == 0)
				dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
			else
				dp[i] = dp[i - 1] + 1;
		}
	}
	cout << dp[num];
	return 0;
}