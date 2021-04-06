#include<vector>
#include <iostream>
#include <queue>
using namespace std;
bool visit[100][100];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
struct info {
	int x, y, depth;
};
queue<info> q;
int solution(vector<vector<int> > maps)
{
	int n = maps.size();
	int m = maps[0].size();
	info newbie = { 0, 0, 1 };
	visit[0][0] = true;
	q.push(newbie);
	while (!q.empty())
	{
		int curx = q.front().x;
		int cury = q.front().y;
		int curdepth = q.front().depth;
		q.pop();
		if (curx == n - 1 && cury == m - 1) return curdepth;
		for (int i = 0; i < 4; i++)
		{
			int nextx = curx + dx[i];
			int nexty = cury + dy[i];
			if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m)
				if (!visit[nextx][nexty] && maps[nextx][nexty] == 1)
				{
					visit[nextx][nexty] = true;
					info temp = { nextx, nexty, curdepth + 1 };
					q.push(temp);
				}
		}
	}
	return -1;
}
