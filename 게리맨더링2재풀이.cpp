#include <iostream>
using namespace std;
int N, map[51][51];
int _min = 987654321;
int point[51][2]; //경계선 배열
int sum = 0;
int calc(int x, int y, int d1, int d2)
{
	int num[6] = { 0, };
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (i < x)
			{
				if (j <= y)
					num[1] += map[i][j];
				else
					num[2] += map[i][j];
			}
			if (x <= i && i < x + d1 && j < point[i][0]) // 1구역
			{
				num[1] += map[i][j];
			}
			if (x <= i && i <= x + d2 && j > point[i][1]) //2구역
			{
				num[2] += map[i][j];
			}
			if (x + d1 <= i && i <= x + d1 + d2 && j < point[i][0])
			{
				num[3] += map[i][j];
			}
			if (x + d2 < i && i <= x + d1 + d2 && j > point[i][1])
			{
				num[4] += map[i][j];
			}
			if (i > x + d1 + d2)
			{
				if (j < y - d1 + d2)
					num[3] += map[i][j];
				else
					num[4] += map[i][j];
			}
		}
	num[5] = sum - num[1] - num[2] - num[3] - num[4];
	
	int max = num[1];
	int min = num[1];
	for (int i = 2; i <= 5; i++)
	{
		if (num[i] > max) max = num[i];
		if (num[i] < min) min = num[i];
	}
	return max - min;
	
}
void check(int x, int y, int d1, int d2)
{
	
	for (int i = 0; i <= d1; i++)
		point[x + i][0] = y - i;
	for (int i = 1; i <= d2; i++)
		point[x + d1 + i][0] = y - d1 + i;
	for (int i = 0; i <= d2; i++)
		point[x + i][1] = y + i;
	for (int i = 1; i <= d1; i++)
		point[x + d2 + i][1] = y + d2 - i;
}
void search()
{
	for(int x = 1; x <= N - 2; x++)
		for (int y = 2; y < N; y++)
			for (int d1d2 = 2; d1d2 <= N - x; d1d2++)
				for (int d1 = 1; d1 <= d1d2 - 1; d1++)
				{
					int d2 = d1d2 - d1;
					if (y - d1 < 1 || y + d2 > N) // d1, d2가 범위에 안맞으면
						continue;
					check(x, y, d1, d2);
					int ret = calc(x, y, d1, d2);
					if (ret < _min) _min = ret;
				}
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			sum += map[i][j];
		}
			

	search();
	cout << _min << endl;
	return 0;
}