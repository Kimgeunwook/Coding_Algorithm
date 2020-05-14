#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
char map[11][11];
int visit[11][11][11][11];
struct info {
	int r_x, r_y, b_x, b_y, answer;
};
queue<info> q;
int bfs()
{
	while (!q.empty())
	{
		
	//	cout<<"q 좌표:" << q.front().r_x<<"," << q.front().r_y << "," << q.front().b_x << "," << q.front().b_y  << endl;
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				if (!(i == 0 && j == 0) && i * j == 0) //4방향 탐색
				{
					if (q.front().answer > 10)//10번이상 돌았으면
						return -1;

					int cur_r_x = q.front().r_x;
					int cur_r_y = q.front().r_y;
					int cur_b_x = q.front().b_x;
					int cur_b_y = q.front().b_y;
					
					while (1)
					{
						if (map[cur_r_x][cur_r_y] != '#' && map[cur_r_x][cur_r_y] != 'O')
						{
							cur_r_x += i;
							cur_r_y += j;
						}
						else
						{
							if (map[cur_r_x][cur_r_y] == '#')
							{
								cur_r_x -= i;
								cur_r_y -= j;
							}
							break;
						}
					}

					while (1)
					{
						if (map[cur_b_x][cur_b_y] != '#' && map[cur_b_x][cur_b_y] != 'O')
						{
							cur_b_x += i;
							cur_b_y += j;
						}
						else
						{
							if (map[cur_b_x][cur_b_y] == '#')
							{
								cur_b_x -= i;
								cur_b_y -= j;
							}
							break;
						}
					}
			//		cout << i << "," << j << endl;
				//	cout<<"땡기고 나서" << cur_r_x << "," << cur_r_y << "," << cur_b_x << "," << cur_b_y << endl;
					if (map[cur_r_x][cur_r_y] == 'O')
					{
						if (map[cur_b_x][cur_b_y] != 'O')
							return q.front().answer;
						else
							continue;
					}
					if (map[cur_b_x][cur_b_y] == 'O')
						continue;
					if (cur_r_x == cur_b_x && cur_r_y == cur_b_y) //위치 겹치면
					{
						if (abs(cur_r_x - q.front().r_x) + abs(cur_r_y - q.front().r_y)
							> abs(cur_b_x - q.front().b_x) + abs(cur_b_y - q.front().b_y))
						{
							cur_r_x -= i;
							cur_r_y -= j;
						}
						else
						{
							cur_b_x -= i;
							cur_b_y -= j;
						}
					}


				//	cout << "최종조정" << cur_r_x << "," << cur_r_y << "," << cur_b_x << "," << cur_b_y << endl;
					
					if (visit[cur_r_x][cur_r_y][cur_b_x][cur_b_y] == 0)
					{
						visit[cur_r_x][cur_r_y][cur_b_x][cur_b_y] = 1;
						info next = { cur_r_x, cur_r_y, cur_b_x, cur_b_y, q.front().answer + 1 };
					//	cout << "push" << cur_r_x << "," << cur_r_y << "," << cur_b_x << "," << cur_b_y << endl;
						q.push(next);
					}
				}
		q.pop();
	//	cout << "q 좌표:" << q.front().r_x << "," << q.front().r_y << "," << q.front().b_x << "," << q.front().b_y << endl;
	}
	return -1;
}
int main()
{
	info start;
	start.answer = 1;

	int M, N;
	cin >> M >> N;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'R')
			{
				start.r_x = i;
				start.r_y = j;
			}
			else if (map[i][j] == 'B')
			{
				start.b_x = i;
				start.b_y = j;
			}
		}
	}
	visit[start.r_x][start.r_y][start.b_x][start.b_y] = 1;
	q.push(start);
	cout << bfs() << endl;
	return 0;
}