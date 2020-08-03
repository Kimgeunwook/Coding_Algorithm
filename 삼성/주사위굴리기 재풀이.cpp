#include <iostream>
using namespace std;
int dice[7]; //주사위 가로, 세로
int map[20][20];
int N, M, x, y, K;
int order[1000];
int main()
{
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < K; i++)
		cin >> order[i];





	for (int i = 0; i < K; i++)
	{
		int temp;
		if (order[i] == 1) //동
		{
			if (y + 1 >= M)
				continue;
			y++;
			temp = dice[3];
			dice[3] = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = temp;
		}
		else if (order[i] == 2) //서
		{
			if (y - 1 < 0)
				continue;
			y--;
			temp = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = dice[1];
			dice[1] = temp;
		}
		else if (order[i] == 3) //북
		{
			if (x - 1 < 0)
				continue;
			x--;
			temp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = temp;
		}
		else if (order[i] == 4) //남
		{
			if (x + 1 >= N)
			{
				continue;
			}
				
			x++;
			temp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = temp;
		}

		if (map[x][y] == 0)
		{
			map[x][y] = dice[6];
		}
		else
		{
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[1] << endl;
	}
	return 0;
}
