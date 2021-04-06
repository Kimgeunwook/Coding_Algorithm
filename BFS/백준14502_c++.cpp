//1011시작
#include <iostream>
#include <queue>
using namespace std;
int N, M, arr[8][8], copy_arr[8][8];
queue<pair<int, int>> q, copy_q;
int _max;
int dx[4] = { -1, 0 , 1 , 0 };
int dy[4] = { 0, 1, 0, -1 };
void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				//바이러스 위치 저장
				copy_q.push({ i,j });
			}
		}
			
}
void _copy()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			copy_arr[i][j] = arr[i][j];

	q = copy_q;
}
void show()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << copy_arr[i][j]<<" ";
		}
		cout << endl;
	}
		
}
void bfs()
{

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		
		//show();
		//cout << "현재 : " << cur.first << " , " << cur.second << endl;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextx = cur.first + dx[i];
			int nexty = cur.second + dy[i];
			if(nextx >= 0 && nextx < N && nexty >= 0 && nexty < M)
				if (copy_arr[nextx][nexty] == 0)
				{
					copy_arr[nextx][nexty] = 2;
					//cout << "다음 : " << nextx << " , " << nexty << endl;
					q.push({nextx, nexty});
				}
		}
	}

}
void get_max()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (copy_arr[i][j] == 0) cnt++;
	if (cnt > _max) _max = cnt;
}
void comb(int cnt)
{
	if (cnt == 3)
	{
		_copy();
		bfs();
		get_max();
	}
	else
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] == 0)
				{
					//cout << cnt << "일때 " << i << "," << j << endl;
					arr[i][j] = 1;
					comb(cnt + 1);
					arr[i][j] = 0;
				}
			}
	}
	
}
int main()
{
	input();
	comb(0);
	cout << _max << endl;
	return 0;
}
