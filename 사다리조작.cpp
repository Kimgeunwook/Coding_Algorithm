#include <iostream>
using namespace std;
int N, M, H, limit;
int map[35][15];
int search()
{
	int cur_loc;
	for (int j = 1; j <= N; j++)
	{
		cur_loc = j;
		for (int i = 1; i <= H; i++)
		{
			if (cur_loc == 1)
			{
				if (map[i][cur_loc] == 1)
					cur_loc++;
			}
			else if (cur_loc == N)
			{
				if (map[i][cur_loc - 1] == 1)
					cur_loc--;
			}
			else
			{
				if (map[i][cur_loc] == 1)
					cur_loc++;
				else if (map[i][cur_loc - 1] == 1)
					cur_loc--;
			}
		}
		if (cur_loc != j)
			return 0;
	}
	return 1;
}
void dfs(int cur_x, int cur_y, int cnt)
{
	if (cnt >= limit)
		return;
	if (search())
	{
		limit = cnt;
		return;
	}
	if (cnt == 3) return;
	for (int i = cur_x; i <= H; i++)
	{
		for (int j = cur_y; j < N; j++)
		{
			if (map[i][j] == 0 && map[i][j - 1] == 0 && map[i][j + 1] == 0)
			{
				map[i][j] = 1;
				dfs(i, j, cnt + 1);
				map[i][j] = 0;
			}
		}
		cur_y = 1;
	}
}
int main()
{
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	limit = 4;
	dfs(1, 1, 0);
	if (limit == 4) cout << -1<<endl;
	else cout << limit << endl;
	return 0;
}