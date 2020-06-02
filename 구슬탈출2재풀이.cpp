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
		
		for(int i = -1; i < 2; i++)
			for(int j = -1; j < 2; j++)
				if (!(i == 0 && j == 0) && (i * j == 0))
				{
					int rx = cur.redx;
					int ry = cur.redy;
					int bx = cur.bluex;
					int by = cur.bluey;
					int rcnt = 0, bcnt = 0;
					while (1)
					{

						if (map[rx + i][ry + j] == '#') //�� ��������
							break;
						else if (map[rx + i][ry + j] == 'O') //���ۿ� ����
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
						if (map[bx + i][by + j] == '#') //�� ��������
							break;
						else if (map[bx + i][by + j] == 'O') //���ۿ� ����
						{
							bx = bx + i;
							by = by + j;
							bcnt++;
							break;
						}
						else //��ĭ�̰ų� ��뱸���̸�
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
					else if(map[rx][ry] == 'O')
					{
						return cur.cnt + 1;
					}

					if (rx == bx && ry == by && map[rx][ry] != 'O')//�������� ��ǥ���� �ƴϸ鼭 ������ �����ΰŸ� ���ؼ� ����
					{
						if (abs(rx - cur.redx) + abs(ry - cur.redy) > abs(bx - cur.bluex) + abs(by - cur.bluey)) //������ �� ���� ���������� == ���ѾߵǸ�
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
	for(int i = 0; i < N; i++)
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