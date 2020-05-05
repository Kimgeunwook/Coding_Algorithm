#include <iostream>
using namespace std;
long long dp[101][10];
long long n, sum = 0;
int main()
{
	cin >> n;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 1; i <= 8; i++)
		dp[2][i] = 2;
	dp[2][9] = 1;

	if (n>2)
		for (int i = 3; i <= n; i++)
			for (int j = 1; j <= 9; j++)
			{
				if (j == 1)
				{
					dp[i][j] = (dp[i - 2][1] + dp[i - 1][j + 1]) % 1000000000;
				}
				else if (j == 9)
				{
					dp[i][j] = (dp[i - 1][j - 1]) % 1000000000;
				}
				else {
					dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
				}
			}



	for (int i = 1; i <= 9; i++)
		sum += dp[n][i];

	cout << sum % 1000000000 << endl;

	return 0;
}