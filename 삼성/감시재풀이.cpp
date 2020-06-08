#include <iostream>
#include <vector>
using namespace std;
struct info{
	int x, y, num;
};
int N, M;
int cctvnum;
int temp[8];
int map[8][8];
int fmap[8][8];
int _min = 987654321;
vector<info> v;
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0 ,1, 0, -1};
void check(int x, int y, int dir)
{
	while (1)
	{
		if (fmap[x + dx[dir]][y + dy[dir]] == 6 || x + dx[dir] < 0 || x + dx[dir] >= N || y + dy[dir] < 0 || y + dy[dir] >= M) //case º®
			break;
		else if (fmap[x + dx[dir]][y + dy[dir]] == 0) //case ºóÄ­
		{
			fmap[x + dx[dir]][y + dy[dir]] = -1;
			x += dx[dir];
			y += dy[dir];
		}
		else // case CCTV
		{
			x += dx[dir];
			y += dy[dir];
		}
	}
}
void simulation(int x, int y, int num, int dir)
{
	if (num == 1)
	{
		check(x, y, dir);
	}
	else if (num == 2)
	{
		check(x, y, dir);
		check(x, y, (dir + 2) % 4);
	}
	else if (num == 3)
	{
		check(x, y, dir);
		check(x, y, (dir + 1) % 4);
	}
	else if (num == 4)
	{
		check(x, y, dir);
		check(x, y, (dir + 3) % 4);
		check(x, y, (dir + 1) % 4);
	}
	else if (num == 5)
	{
		check(x, y, dir);
		check(x, y, (dir + 1) % 4);
		check(x, y, (dir + 2) % 4);
		check(x, y, (dir + 3) % 4);
	}
}
int answer()
{
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (fmap[i][j] == 0)
				ret++;
	return ret;
}
void dfs(int cnt)
{
	if (cnt == cctvnum)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				fmap[i][j] = map[i][j];
		
		for (int i = 0; i < cctvnum; i++)
			simulation(v[i].x, v[i].y, v[i].num , temp[i]);

		int ret = answer();
		if (ret < _min) 
			_min = ret;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			temp[cnt] = i;
			dfs(cnt + 1);
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6)
			{
				info temp = { i, j, map[i][j]};
				v.push_back(temp);
			}
		}
	cctvnum = v.size();
	dfs(0);

	cout << _min << endl;
}
