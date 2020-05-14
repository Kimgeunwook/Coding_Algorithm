#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
bool map[1001][1001];
int dp[1001][1001];
int current_max = 0;
int main()
{
	int row, col;
	cin >> row >> col;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
		{
			if (map[i - 1][j] == 0 || map[i][j - 1] == 0)
			{
				if (map[i][j] == 1)
					dp[i][j] = 1;
			}
			else
			{
				int a = min(dp[i - 1][j], dp[i][j - 1]);
				if (map[i][j] == 1)
				{
					if (dp[i - a][j - a] != 0)
						dp[i][j] = a + 1;
					else
						dp[i][j] = a;
				}
				else
					dp[i][j] = 0;
			}
		}

	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (dp[i][j] > current_max)
				current_max = dp[i][j];

	cout << current_max * current_max;
	return 0;
}
