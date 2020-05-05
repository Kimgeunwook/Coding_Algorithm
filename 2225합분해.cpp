#include <iostream>
using namespace std;
int a, b;
int dp[201][201];
int main()
{
	cin >> a >> b;
	for (int i = 1; i <= a; i++)
		dp[1][i] = 1;

	for (int i = 1; i <= b; i++)
		dp[i][1] = i;

	for (int i = 2; i <= b; i++)
		for (int j = 2; j <= a; j++)
			dp[i][j] += (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;

	cout << dp[b][a] % 1000000000;
	return 0;
}