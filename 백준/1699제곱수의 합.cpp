#include <iostream>
using namespace std;
#include <cmath>
#include <algorithm>
int dp[100001];
int main()
{
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		int min = 987654321;
		for (int j = sqrt(i); j >= 1; j--)
		{
			if (((i / (j*j)) + dp[i - (i / (j*j))*(j*j)]) < min)
				min = (i / (j*j)) + dp[i - (i / (j*j))*(j*j)];
		}
		dp[i] = min;
	}
	cout << dp[num];
	return 0;
}
