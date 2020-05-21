#include <iostream>
using namespace std;
int N;
int map[30][30];
int visit[30][30];
int _max = 2;

void move(int dx, int dy)
{
	if ((dx == -1 && dy == 0)) //북
	{
		for (int j = 0; j < N; j++)
		{
			for (int a = 0; a < N; a++)
				for (int b = 0; b < N;b++)
					visit[a][b] = 0;
			for (int i = 1; i < N; i++)
			{
				if (map[i][j] == 0) continue; //주체가 빈칸이면
				int k;
				for (k = 1; ; k++)
				{
					if (i - k == 0 || map[i - k][j] != 0)
						break; //범위
				}
				if (map[i - k][j] == 0) //목표가 빈칸이면
				{
					map[i - k][j] = map[i][j];
					map[i][j] = 0;
				}
				else //목표가 숫자면
				{
					if (map[i - k][j] == map[i][j] && visit[i - k][j] == 0) //같은 숫자면
					{
						visit[i - k][j] = 1;
						map[i - k][j] *= 2;
						map[i][j] = 0;
					}
					else // 숫자가 다르거나 합쳐진 자리면
					{
						map[i - k + 1][j] = map[i][j];
						if (k != 1)
							map[i][j] = 0;
					}
				}
				
			}
		}
	}
	else if ((dx == 0 && dy == 1) ) // 동
	{
		for (int i = 0; i < N; i++)
		{
			for (int a = 0; a < N; a++)
				for (int b = 0; b < N; b++)
					visit[a][b] = 0;
			for (int j = N - 2; j >= 0; j--)
			{
				if (map[i][j] == 0) continue; // 주체가 빈칸이면
				int k;
				for (k = 1; ; k++)
				{
					if (j + k == N - 1 || map[i][j + k] != 0)
						break; //범위
				}
				if (map[i][j + k] == 0)
				{
					map[i][j + k] = map[i][j];
					map[i][j] = 0;
				}
				else
				{
					if (map[i][j + k] == map[i][j] && visit[i][j + k] == 0) // 합쳐지는 경우
					{
						visit[i][j + k] = 1;
						map[i][j + k] *= 2;
						map[i][j] = 0;
					}
					else // 안합쳐지는 경우
					{
						map[i][j + k - 1] = map[i][j];
						if (k != 1)
							map[i][j] = 0;
					}
				}
			}
		}
	}
	else if ((dx == 1 && dy == 0)) //남
	{
		for (int j = 0; j < N; j++)
		{
			for (int a = 0; a < N; a++)
				for (int b = 0; b < N; b++)
					visit[a][b] = 0;
			for (int i = N - 2; i >= 0; i--)
			{
				if (map[i][j] == 0) continue; // 주체가 빈칸이면
				int k;
				for (k = 1; ; k++)
				{
					if (i + k == N -1 || map[i + k][j] != 0)
						break; //범위
				}
				if (map[i + k][j] == 0) //빈칸이면
				{
					map[i + k][j] = map[i][j];
					map[i][j] = 0;
				}
				else
				{
					if (map[i + k][j] == map[i][j] && visit[i + k][j] == 0) //합쳐지는경우
					{
						visit[i + k][j] = 1;
						map[i + k][j] *= 2;
						map[i][j] = 0;
					}
					else
					{
						map[i + k - 1][j] = map[i][j];
						if (k != 1)
							map[i][j] = 0;
					}
				}
				
			}
		}
	}
	else if ((dx == 0 && dy == -1)) // 서
	{
		for (int i = 0; i < N; i++)
		{
			for (int a = 0; a < N; a++)
				for (int b = 0; b < N; b++)
					visit[a][b] = 0;
			for (int j = 1; j < N; j++)
			{
				if (map[i][j] == 0) continue; // 주체가 빈칸이면
				int k;
				for (k = 1; ; k++)
				{
					if (j - k == 0 || map[i][j - k] != 0)
						break; //범위
				}
				if (map[i][j - k] == 0)
				{
					map[i][j - k] = map[i][j];
					map[i][j] = 0;
				}
				else
				{
					if (map[i][j - k] == map[i][j] && visit[i][j - k] == 0) // 합쳐지는 경우
					{
						visit[i][j - k] = 1;
						map[i][j - k] *= 2;
						map[i][j] = 0;
					}
					else // 안합쳐지는 경우
					{
						map[i][j - k + 1] = map[i][j];
						if (k != 1)
							map[i][j] = 0;
					}
				}
				
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] > _max)
				_max = map[i][j];
}
void dfs(int cnt)
{
	if (cnt >= 5)
	{
		return;
	}
		
	int temp[30][30];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			temp[i][j] = map[i][j];

	for (int i = -1; i < 2; i++)
		for(int j = -1; j < 2; j++)
			if (!(i == 0 && j == 0) && i * j == 0)
			{
				move(i, j);
				dfs(cnt + 1);
				for (int a = 0; a < N; a++) //back tracking
					for (int b = 0; b < N; b++)
						map[a][b] = temp[a][b];
			}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	dfs(0);
	cout << _max << endl;
	return 0;
}