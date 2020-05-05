#include <iostream>
using namespace std;
int dice[7], temp[7], map[20][20]; //주사위에 쓰여지는 숫자,주사위 숫자 복사본 ,지도에 쓰여지는 숫자
int N, M, x, y, order_num;// 세로/ 가로 / 현재 세로 좌표 현재 가로 좌표 / 명령 개수 
int forward_direction;// 이동 방향 
int main()
{
	cin >> N >> M >> x >> y >> order_num;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < order_num; i++)
	{
		for (int j = 1; j <= 6; j++)
			temp[j] = dice[j];

		bool valid_flag = 0; // 범위 체크 플래그
		cin >> forward_direction;//이동방향 입력받기
		switch (forward_direction)//이동방향에 따라 주사위 전개도 숫자 바꿔주기
		{
		case 1://동쪽
			if (y + 1 <= M - 1)
			{
				y = y + 1;
				valid_flag = 1;
				dice[1] = temp[3];
				dice[4] = temp[1];
				dice[6] = temp[4];
				dice[3] = temp[6];

				break;
			}
			else
				break;
		case 2://서쪽
			if (y - 1 >= 0)
			{
				y = y - 1;
				valid_flag = 1;
				dice[3] = temp[1];
				dice[1] = temp[4];
				dice[4] = temp[6];
				dice[6] = temp[3];
				break;
			}
			else
				break;
		case 3://북쪽
			if (x - 1 >= 0)
			{
				x = x - 1;
				valid_flag = 1;
				dice[2] = temp[1];
				dice[6] = temp[2];
				dice[5] = temp[6];
				dice[1] = temp[5];
				break;
			}
			else
				break;


		case 4://남쪽
			if (x + 1 <= N - 1)
			{
				x = x + 1;
				valid_flag = 1;
				dice[1] = temp[2];
				dice[2] = temp[6];
				dice[6] = temp[5];
				dice[5] = temp[1];
				break;
			}
			else
				break;
		}
		if (valid_flag)
		{
			if (map[x][y] == 0)
				map[x][y] = dice[6];
			else
			{
				dice[6] = map[x][y];
				map[x][y] = 0;
			}
			if (valid_flag) //지도밖으로 안 벗어 났으면 윗면 출력
				cout << dice[1] << endl;
		}

	}
	return 0;
}