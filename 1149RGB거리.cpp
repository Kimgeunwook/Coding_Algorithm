#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int num;
	int dp[1000][3];
	int n[1000][3];
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;
		n[i][0] = r;
		n[i][1] = g;
		n[i][2] = b;
	}
	dp[0][0] = n[0][0];
	dp[0][1] = n[0][1];
	dp[0][2] = n[0][2];
	for (int i = 1; i < num; i++)
	{
		dp[i][0] = min(dp[i - 1][1] + n[i][0], dp[i - 1][2] + n[i][0]);
		dp[i][1] = min(dp[i - 1][0] + n[i][1], dp[i - 1][2] + n[i][1]);
		dp[i][2] = min(dp[i - 1][0] + n[i][2], dp[i - 1][1] + n[i][2]);
	}
	cout << min(min(dp[num - 1][0], dp[num - 1][1]), dp[num - 1][2]) << endl;
	return 0;
	//
}