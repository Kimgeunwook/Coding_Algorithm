//15:48½ÃÀÛ
#include <iostream>
using namespace std;
#include <algorithm>
int N;
int map[501][501];
int dp[501][501];
int _max = -1;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0 ,1 };

int dfs(int x, int y)
{
	if (dp[x][y] != 0) return dp[x][y];
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] > map[x][y])
		{
			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
		}
	}
	return dp[x][y];
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			_max = max(_max , dfs(i, j));
			
	cout << _max << endl;
	return 0;
}
