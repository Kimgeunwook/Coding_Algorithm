//1432Ω√¿€ #1700≥°
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int  N, W, H;
int map[15][12], copymap[15][12], originalmap[15][12];
int _min = 987654321;
vector<int> v;
queue<pair<int, int>> q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void init()
{
	cin >> N >> W >> H;
	_min = 987654321;
	for(int i = 0 ; i < 15; i++)
		for (int j = 0; j < 12; j++)
		{
			map[i][j] = 0;
			copymap[i][j] = 0;
			originalmap[i][j] = 0;
		}

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			cin >> map[i][j];
			copymap[i][j] = map[i][j];
			originalmap[i][j] = map[i][j];
		}
			
}
void push_top_pos(int n)
{
	for (int i = 0; i < H; i++)
	{
		if (map[i][n] != 0)
		{
			q.push({i,n});
			break;
		}
	}
}
void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int curnum = copymap[x][y];
		map[x][y] = 0;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < curnum; j++)
			{
				int nx = x + j * dx[i];
				int ny = y + j * dy[i];

				if (nx >= 0 && nx < H && ny >= 0 && ny < W)
					if (map[nx][ny] != 0)
					{
						q.push({ nx, ny });
						map[nx][ny] = 0;
					}
			}
			
		}

		q.pop();
	}
}
void pulldown()
{
	for(int j = 0 ; j < W; j++)
		for (int i = H - 2; i >= 0; i--)
		{
			if (map[i][j] != 0)
			{
				int k = 1;
				while (i + k < H)
				{
					if (map[i + k][j] != 0) break;
					k++;
				}
				if (k > 1)
				{
					map[i + k - 1][j] = map[i][j];
					map[i][j] = 0;
				}
				
			}
		}

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			copymap[i][j] = map[i][j];
		}
}
int howRemain()
{
	int cnt = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (map[i][j] != 0) cnt++;
		}
	}
	return cnt;
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		push_top_pos(v[i]);
		bfs();
		pulldown();
	}
	_min = min(_min, howRemain());
}

void dfs(int n)
{
	if (n == N)
	{
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				map[i][j] = originalmap[i][j];
				copymap[i][j] = originalmap[i][j];
			}
		solve();
	}
	else 
	{
		for (int i = 0; i < W; i++)
		{
			v.push_back(i);
			dfs(n + 1);
			v.pop_back();
		}
	}
	
}
int main()
{
	int T; cin >> T;
	for (int i = 1; i <= T; i++)
	{
		init();
		dfs(0);
		cout << "#" << i << " " << _min << endl;
	}
	return 0;
}