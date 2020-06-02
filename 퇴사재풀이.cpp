#include <iostream>
using namespace std;
int N;
int _max = -987654321;
int arr[2][16];
int dp[16];
int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[0][i] >> arr[1][i];

	for (int i = N; i >= 1; i--)
	{
		if (i + arr[0][i] <= N + 1)
		{
			if (arr[1][i] + dp[i + arr[0][i]] > dp[i + 1])
				dp[i] = arr[1][i] + dp[i + arr[0][i]];
			else
				dp[i] = dp[i + 1];
		}
		else
			dp[i] = dp[i + 1];
	}
	cout << dp[1] << endl;
	return 0;
}