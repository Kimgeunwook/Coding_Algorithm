#include <iostream>
#include <queue>
using namespace std;
struct info
{
	int cnt, original[20][20];
};
int N;
int map[20][20];
int _max = -9876543321;
queue<info> q;
void find_max(int temp[20][20])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (temp[i][j] > _max)
				_max = temp[i][j];
}
void bfs()
{
	while (!q.empty())
	{
		
		info cur = q.front();
		int temp[20][20];
		if (cur.cnt == 6)//종료조건
			return;

		for(int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				if (!(i == 0 && j == 0) && (i * j == 0))
				{
					
					if (i == -1 && j == 0) //북
					{
						for (int a = 0; a < N; a++) //현재 원본 복사
							for (int b = 0; b < N; b++)
								temp[a][b] = cur.original[a][b];
					}
					else if (i == 0 && j == -1) //서
					{
						for (int a = 0; a < N; a++) //현재 원본 복사
							for (int b = 0; b < N; b++)
								temp[a][b] = cur.original[N - 1 - b][a];
					}
					else if (i == 0 && j == 1) // 동
					{
						for (int a = 0; a < N; a++) //현재 원본 복사
							for (int b = 0; b < N; b++)
								temp[a][b] = cur.original[b][N - 1 - a];
					}
					else if (i == 1 && j == 0) //남
					{
						for (int a = 0; a < N; a++) //현재 원본 복사
							for (int b = 0; b < N; b++)
								temp[a][b] = cur.original[N - 1 - a][b];
					}
					for (int b = 0; b < N; b++)
					{
						int check[20] = { 0, }; // 합쳐진거 체크
						for (int a = 1; a < N; a++)
						{
							int k = 1;
							int flag = 0;
							while (a - k >= 0)
							{
								if (temp[a - k][b] == 0) //빈칸이면
								{
									k++;
								}
								else if (temp[a - k][b] == temp[a][b] && check[a - k] == 0) // 같고 합친기록이 없는애면
								{
									temp[a][b] = 0;
									temp[a - k][b] *= 2;
									check[a - k] = 1;
									flag = 1;
									break;
								}
								else
								{
									temp[a - k + 1][b] = temp[a][b];
									if (k != 1)
										temp[a][b] = 0;
									flag = 1;
									break;
								}
							}
							if (flag == 0)
							{
								temp[a - k + 1][b] = temp[a][b];
								temp[a][b] = 0;
							}
								
							
						}
					}
					find_max(temp);
					info next;
					next.cnt = cur.cnt + 1;
					for (int a = 0; a < N; a++)
						for (int b = 0; b < N; b++)
							next.original[a][b] = temp[a][b];
					q.push(next);
				}
		q.pop();
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	info t;
	t.cnt = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			t.original[i][j] = map[i][j];

	q.push(t);

	bfs();
	cout << _max << endl;
	return 0;
}