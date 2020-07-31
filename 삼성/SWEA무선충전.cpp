#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
struct AP {
	int apnum, x, y, size, P, max, nextmax;
};
int T, M, A;
int dirA[100], dirB[100];
AP routeA[101], routeB[101];
AP map[11][11];
queue<AP> q;
int _max = 0;
int ax = 1, ay = 1, bx = 10, by = 10;
int dx[5] = {0 , -1, 0 ,1, 0};
int dy[5] = { 0 , 0, 1 ,0, -1 };
void checkmap(int n, int x, int y, int size, int p)
{
	for(int i =1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			if (abs(i - x) + abs(j - y) <= size)
			{
				if (p > map[i][j].max) // 새로들온놈이 젤앞에애보다 크면
				{
					map[i][j].apnum = n;
					map[i][j].nextmax = map[i][j].max;
					map[i][j].max = p;
				}
				else if (p > map[i][j].nextmax) // 새로들온놈이 두번째애보다 크면
				{
					map[i][j].nextmax = p;
				}
			}
		}
}
void dfs(int cnt)
{
	if (cnt == M + 1)
	{
		int ret = 0;
		for (int i = 0; i <= M; i++)
		{
			if (routeA[i].apnum == routeB[i].apnum && routeB[i].apnum != 0) // 겹치면
			{
				ret += max(map[routeA[i].x][routeA[i].y].max + map[routeB[i].x][routeB[i].y].nextmax, map[routeB[i].x][routeB[i].y].max + map[routeA[i].x][routeA[i].y].nextmax);
			}
			else
			{
				ret += map[routeA[i].x][routeA[i].y].max + map[routeB[i].x][routeB[i].y].max;
			}
		}
		if (_max < ret) _max = ret;
	}
	else
	{
		AP newbieA = { map[ax][ay].apnum ,ax, ay, 0, 0, map[ax][ay].max, map[ax][ay].nextmax };
		routeA[cnt] = newbieA;
		AP newbieB = { map[bx][by].apnum ,bx, by, 0, 0, map[bx][by].max, map[bx][by].nextmax };
		routeB[cnt] = newbieB;
		ax += dx[dirA[cnt]];
		ay += dy[dirA[cnt]];
		bx += dx[dirB[cnt]];
		by += dy[dirB[cnt]];
		dfs(cnt + 1);	
	}
}
int main()
{
	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++)
	{
		ax = 1, ay = 1, bx = 10, by = 10;
		_max = 0;
		AP init = {0,0,0,0,0,0,0};
		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 10; j++)
				map[i][j] = init;
		cin >> M >> A;
		for (int i = 0; i < M; i++)
			cin >> dirA[i];
		for (int i = 0; i < M; i++)
			cin >> dirB[i];


		for (int i = 0; i < A; i++)
		{
			int x, y, c, p;
			cin >> y >> x >> c >> p;
			AP newbie = { i, x, y, c, p, 0, 0 };
			q.push(newbie);
		}
		while (!q.empty())
		{
			AP cur = q.front();
			q.pop();
			checkmap(cur.apnum + 1, cur.x, cur.y, cur.size, cur.P);
		}
		dfs(0);
		cout<<"#"<<testcase<<" " << _max << endl;
	}
	
	return 0;
}
