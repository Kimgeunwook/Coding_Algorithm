//2020
#include <iostream>
#include <queue>
using namespace std;
int totalCase, w, h, curx, cury;
char map[1002][1002], tempmap[1002][1002];
bool visit[1002][1002];
typedef pair<int, int> Pair;
queue<Pair> fireq, curq;
int dx[4] = { -1, 0 ,1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Input()
{
	cin >> w >> h;
	while (!fireq.empty()) fireq.pop();

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '@') 
				curq.push({ i,j });
			else if (map[i][j] == '*')
				fireq.push({ i, j });

			tempmap[i][j] = map[i][j];
			visit[i][j] = false;
		}
			
}

void fire_bfs()
{
	queue<Pair> temp;
	while (!fireq.empty())
	{
		Pair cur = fireq.front();
		fireq.pop();
		for (int i = 0; i < 4; i++)
		{
			if (tempmap[cur.first + dx[i]][cur.second + dy[i]] == '.' || tempmap[cur.first + dx[i]][cur.second + dy[i]] == '@')
			{
				temp.push({ cur.first + dx[i] , cur.second + dy[i] });
				tempmap[cur.first + dx[i]][cur.second + dy[i]] = '*';
			}
		}
	}
	fireq = temp;
}
bool cur_bfs()
{
	queue<Pair> temp;
	while (!curq.empty())
	{
		Pair cur = curq.front();
		curq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextx = cur.first + dx[i];
			int nexty = cur.second + dy[i];
			if (nextx == 0 || nexty == 0 || nextx == h + 1 || nexty == w + 1) return true;
			if (tempmap[nextx][nexty] == '.' && !visit[nextx][nexty])
			{
				visit[nextx][nexty] = true;
				temp.push({ nextx , nexty });
			}
		}
	}
	curq = temp;
	return false;
}
int main()
{
	cin >> totalCase;
	for (int k = 0; k < totalCase; k++)
	{
		Input();
		int answer = 0;
		while (1)
		{
			answer++;
			fire_bfs();
			bool ret = cur_bfs();
			if (ret) 
			{
				while (!curq.empty()) curq.pop();
				cout << answer << endl;
				break;
			}
			if (curq.empty()) {
				cout << "IMPOSSIBLE" << endl;
				break;
			}
		}
		
	}
	return 0;
}