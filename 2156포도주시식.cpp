#include <iostream>
using namespace std;
#include <algorithm>
int dp[10001];
int sum[10001];
int main()
{
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> dp[i];

	for (int i = 1; i <= num; i++)
	{
		if (i == 1)
			sum[1] = dp[1];
		else if (i == 2)
			sum[2] = dp[1] + dp[2];
		else
			sum[i] = max(max(sum[i - 3] + dp[i - 1] + dp[i], sum[i - 2] + dp[i]), sum[i - 1]);
	}
	cout << sum[num];
	return 0;
}