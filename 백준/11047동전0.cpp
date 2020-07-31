#include <iostream>
using namespace std;
int dp[11];
int main()
{
	int a, b, c, count = 0;
	cin >> a >> b;
	for (int i = 1; i <= a; i++)
	{
		cin >> dp[i];
		if (dp[i] <= b)
			c = i;
	}
	for (int i = c; i >= 1; i--)
	{
		if (dp[i] <= b)
		{
			count += b / dp[i];
			b = b % dp[i];
		}
	}
	cout << count;
	return 0;
}