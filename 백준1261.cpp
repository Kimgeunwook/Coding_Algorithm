#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
int map[101][101];
int record[101][101];
queue<pair<int, int >> q;
int _min = 987654321;
void bfs()
{
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				if ((i * j == 0) && !(i == 0 && j == 0))
					if (cur_x + i > 0 && cur_x + i <= N && cur_y + j > 0 && cur_y + j <= M)
					{
						if (map[cur_x + i][cur_y + j] == 1)
						{
							if (record[cur_x + i][cur_y + j] > record[cur_x][cur_y] + 1)
							{
								record[cur_x + i][cur_y + j] = record[cur_x][cur_y] + 1;
								q.push({ cur_x + i , cur_y + j });
							}
						}
						else
						{
							if (record[cur_x + i][cur_y + j] > record[cur_x][cur_y])
							{
								record[cur_x + i][cur_y + j] = record[cur_x][cur_y];
								q.push({ cur_x + i , cur_y + j });
							}
						}
						/*if (map[cur_x + i][cur_y + j] == 1)
						{
							if (record[cur_x + i][cur_y + j] > record[cur_x][cur_y])
							{
								record[cur_x + i][cur_y + j] = min(record[cur_x + i][cur_y + j], record[cur_x][cur_y] + 1);
								q.push({ cur_x + i , cur_y + j });
							}
						}
						else
						{
							record[cur_x + i][cur_y + j] = min(record[cur_x + i][cur_y + j], record[cur_x][cur_y]);
							q.push({ cur_x + i , cur_y + j });
						}*/
						
					}
	}
}
int main()
{

	cin >> M >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			int a = 0;
			scanf("%1d", &a);
			map[i][j] = a;
			record[i][j] = 987654321;
		}

	record[1][1] = 0;
	q.push({ 1,1 });
	bfs();
	cout << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cout << record[i][j];
		cout << endl;
	}
	cout << record[N][M] << endl;
	return 0;
}