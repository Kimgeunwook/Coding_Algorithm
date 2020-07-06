#include <iostream>
using namespace std;
int map[51][51], point_map[51][51], count_map[51][51], R, C, T;

int main()
{
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> map[i][j];

	for (int U = 0; U < T; U++)
	{
		for (int i = 1; i <= R; i++) // 나누기5한값, 주변에 줄수있는칸 개수 
			for (int j = 1; j <= C; j++)
			{
				if (map[i][j] != -1)
					point_map[i][j] = map[i][j] / 5;

				if (point_map[i][j] != 0)
					for (int k = -1; k < 2; k++)
						for (int p = -1; p < 2; p++)
							if (k*p == 0 && !(k == 0 && p == 0))
								if (i + k >= 1 && i + k <= R && j + p >= 1 && j + p <= C)
									if (map[i + k][j + p] != -1)
										count_map[i][j]++;

				map[i][j] -= point_map[i][j] * count_map[i][j];
			}

		///////////////////////////////////////////////////////////

		///////// 미세먼지 나눠주고
		for (int q = 1; q <= R; q++)
			for (int w = 1; w <= C; w++)
			{
				if (point_map[q][w] != 0)
				{
					for (int k = -1; k < 2; k++)
						for (int p = -1; p < 2; p++)
							if (k*p == 0 && !(k == 0 && p == 0))
								if (q + k >= 1 && q + k <= R && w + p >= 1 && w + p <= C)
									if (map[q + k][w + p] != -1)
										map[q + k][w + p] += point_map[q][w];
				}
			}
		////////////
		//////청정기로 밀기
		int flag = 0;
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				if (map[i][j] == -1)
				{
					for (int a = i - 1; a > 1; a--)
						map[a][1] = map[a - 1][1];
					for (int a = 1; a < C; a++)
						map[1][a] = map[1][a + 1];
					for (int a = 1; a < i; a++)
						map[a][C] = map[a + 1][C];
					for (int a = C; a > 2; a--)
						map[i][a] = map[i][a - 1];
					map[i][2] = 0;
					///////////////////////////////////
					for (int a = i + 2; a < R; a++)
						map[a][1] = map[a + 1][1];
					for (int a = 1; a < C; a++)
						map[R][a] = map[R][a + 1];
					for (int a = R; a > i + 1; a--)
						map[a][C] = map[a - 1][C];
					for (int a = C; a > 2; a--)
						map[i + 1][a] = map[i + 1][a - 1];
					map[i + 1][2] = 0;
					flag = 1;
					break;
				}

			}
			if (flag == 1) break;
		}
		///////////////////////////////////////////////////////////
		for (int i = 1; i <= R; i++) // 초기화
			for (int j = 1; j <= C; j++)
			{
				point_map[i][j] = 0;
				count_map[i][j] = 0;
			}
	}
	int sum = 0;
	for (int i = 1; i <= R; i++) //미세먼지 합 구하기
		for (int j = 1; j <= C; j++)
			sum += map[i][j];
	cout << sum + 2;
	return 0;
}