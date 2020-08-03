#include <iostream>
#include <algorithm>
using namespace std;
char map[21][21];
int visit[27];
int r, c;
int _max = -1;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
void dfs(int x, int y, int depth)
{
	_max = max(_max, depth);
	for (int i = 0; i < 4; i++) 
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 1 && nx <= r && ny >= 1 && ny <= c)
		{
			if (visit[map[nx][ny] - 'A'] == 0) 
			{
				visit[map[nx][ny] - 'A'] = 1;
				dfs(nx, ny, depth + 1);
				visit[map[nx][ny] - 'A'] = 0;
			}
		}
	}
}
int main()
{
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> map[i][j];

	visit[map[1][1] - 'A'] = 1;
	dfs(1, 1, 1);

	cout << _max << endl;
	return 0;
}