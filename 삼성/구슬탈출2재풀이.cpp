#include <iostream>
using namespace std;
#include <queue>
#include <math.h>
struct BALL
{
	int redx, redy, bluex, bluey, cnt;
};
int N, M;
char map[10][10];
int visit[10][10][10][10];
queue<BALL> q;
int bfs()
{
	while (!q.empty())
	{
		BALL cur = q.front();
		q.pop();
		if (cur.cnt == 10)
			return -1;

		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				if (!(i == 0 && j == 0) && (i * j == 0))
				{
					int rx = cur.redx;
					int ry = cur.redy;
					int bx = cur.bluex;
					int by = cur.bluey;
					int rcnt = 0, bcnt = 0;
					while (1)
					{

						if (map[rx + i][ry + j] == '#') //벽 만났으면
							break;
						else if (map[rx + i][ry + j] == 'O') //구멍에 골인
						{
							rx = rx + i;
							ry = ry + j;
							rcnt++;
							break;
						}
						else
						{
							rcnt++;
							rx = rx + i;
							ry = ry + j;
						}
					}

					while (1)
					{
						if (map[bx + i][by + j] == '#') //벽 만났으면
							break;
						else if (map[bx + i][by + j] == 'O') //구멍에 골인
						{
							bx = bx + i;
							by = by + j;
							bcnt++;
							break;
						}
						else //빈칸이거나 상대구슬이면
						{
							bcnt++;
							bx = bx + i;
							by = by + j;
						}
					}

					if (map[bx][by] == 'O')
					{
						continue;
					}
					else if (map[rx][ry] == 'O')
					{
						return cur.cnt + 1;
					}

					if (rx == bx && ry == by && map[rx][ry] != 'O')//두지점이 목표점이 아니면서 같으면 움직인거리 비교해서 조정
					{
						if (abs(rx - cur.redx) + abs(ry - cur.redy) > abs(bx - cur.bluex) + abs(by - cur.bluey)) //빨강이 더 많이 움직였으면 == 비켜야되면
						{
							rx -= i;
							ry -= j;
						}
						else {
							bx -= i;
							by -= j;
						}
					}

					BALL next = { rx, ry, bx, by, cur.cnt + 1 };
					if (visit[rx][ry][bx][by] == 0)
					{
						visit[rx][ry][bx][by] = 1;
						q.push(next);
					}
					else
					{
						continue;
					}

				}

	}
	return -1;
}
int main()
{
	BALL init;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'R')
			{
				init.redx = i;
				init.redy = j;
			}
			if (map[i][j] == 'B')
			{
				init.bluex = i;
				init.bluey = j;
			}
		}
	init.cnt = 0;
	q.push(init);

	visit[init.redx][init.redy][init.bluex][init.bluey] = 1;
	cout << bfs() << endl;

	return 0;
}
