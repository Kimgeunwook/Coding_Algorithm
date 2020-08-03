//21:31시작
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 987654321
struct info {
	int a, b, c, depth;
};
queue<info> q;
int L, R, C;
char map[30][30][30];
int visit[30][30][30];
int start[3], _end[3];
int _min = INF;
int dir[6][3] = { {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 0, -1}, {0, -1, 0}, {-1, 0 ,0} };
void bfs()
{
	while (!q.empty())
	{
		info cur = q.front();
		q.pop();
		if (cur.a == _end[0] && cur.b == _end[1] && cur.c == _end[2])
		{
			_min = min(_min, cur.depth);
			continue;
		}
		for (int i = 0; i < 6; i++)
		{
			int na = cur.a + dir[i][0];
			int nb = cur.b + dir[i][1];
			int nc = cur.c + dir[i][2];
			if (na >= 0 && na < L && nb >= 0 && nb < R && nc >= 0 && nc < C && visit[na][nb][nc] == 0 && map[na][nb][nc] != '#')
			{
				visit[na][nb][nc] = 1;
				info temp = { na, nb, nc, cur.depth + 1 };
				q.push(temp);
			}
		}
	}
}
int main()
{
	while (1)
	{
		//Input
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		for (int k = 0; k < L; k++)
			for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++)
				{
					cin >> map[k][i][j];
					if (map[k][i][j] == 'S')
					{
						start[0] = k;
						start[1] = i;
						start[2] = j;
					}
					else if (map[k][i][j] == 'E')
					{
						_end[0] = k;
						_end[1] = i;
						_end[2] = j;
					}
				}


		//bfs
		info newbie = { start[0], start[1] , start[2], 0 };
		q.push(newbie);
		visit[start[0]][start[1]][start[2]] = 1;
		bfs();

		//정답 출력
		if (_min == INF) cout << "Trapped!" << endl;
		else cout << "Escaped in " << _min << " minute(s)." << endl;

		//visit초기화 min값 초기화
		for (int k = 0; k < L; k++)
			for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++)
					visit[k][i][j] = 0;
		_min = INF;

	}


	return 0;
}