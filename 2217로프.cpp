#include <iostream>
using namespace std;
int answer[10001];
int dp[10001];
int main()
{
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		int a;
		cin >> a;
		dp[a] += 1;
	}
	int sum = 0;
	for (int i = 10000; i >= 1; i--)
		if (dp[i] != 0)
		{
			answer[i] = sum + dp[i];
			sum += dp[i];
		}
	int max = 0;
	for (int i = 0; i <= 10000; i++)
		if (i*answer[i] > max)
			max = i * answer[i];

	cout << max;




	return 0;
}