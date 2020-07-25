#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[1001], dp[1001];
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
		}
	}

	int _max = -1;
	for (int i = 1; i <= N; i++)
	{
		_max = max(_max, dp[i]);
	}
	cout << _max << endl;

	return 0;
}