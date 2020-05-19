#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> q;
vector<int> q_num;
vector<pair<int, int>> temp;
int N, M, num_camera = 0, _min = 987654321;
int map[8][8];
void move(int cur_x, int cur_y, int dir)
{
	if (dir == 0)
	{
		if (cur_x > 0)
		{
			for (int i = cur_x - 1; i >= 0; i--)
			{
				if (map[i][cur_y] == 0)
				{
					temp.push_back(make_pair(i,cur_y));
					map[i][cur_y] = 7;
				}
				else if (map[i][cur_y] == 6)
					break;
			}
		}
	}
	else if (dir == 1)
	{
		if (cur_y < M - 1)
		{
			for (int j = cur_y + 1; j < M; j++)
			{
				if (map[cur_x][j] == 0)
				{
					temp.push_back(make_pair(cur_x, j));
					map[cur_x][j] = 7;
				}
				else if (map[cur_x][j] == 6)
					break;
			}
		}
	}
		
	else if (dir == 2)
	{
		if (cur_x < N - 1)
		{
			for (int i = cur_x + 1; i < N; i++)
			{
				if (map[i][cur_y] == 0)
				{
					temp.push_back(make_pair(i, cur_y));
					map[i][cur_y] = 7;
				}
				else if (map[i][cur_y] == 6)
					break;
			}
		}
	}
		
	else if (dir == 3)
	{
		if (cur_y > 0)
		{
			for (int j = cur_y - 1; j >= 0; j--)
			{
				if (map[cur_x][j] == 0)
				{
					temp.push_back(make_pair(cur_x, j));
					map[cur_x][j] = 7;
				}
				else if (map[cur_x][j] == 6)
					break;
			}
		}
	}
}
void spread(int cur_x, int cur_y, int dx, int dy, int cctv_num)
{
	int dir; // 0:북    1:동     2:남      3:서
	if (dx == -1 && dy == 0) //북
		dir = 0;
	else if (dx == 0 && dy == 1) //동
		dir = 1;
	else if (dx == 1 && dy == 0) //남
		dir = 2;
	else if (dx == 0 && dy == -1) //서
		dir = 3;

	int left, right, opp;
	if (dir == 0)
		left = 3;
	else
		left = dir - 1;

	if (dir == 3)
		right = 0;
	else
		right = dir + 1;

	opp = (dir + 2) % 4;
	
	if (cctv_num == 1)
	{
		move(cur_x, cur_y, dir);
	}
		
	else if (cctv_num == 2)
	{
		move(cur_x, cur_y, left);
		move(cur_x, cur_y, right);
	}
	else if (cctv_num == 3)
	{
		move(cur_x, cur_y, dir);
		move(cur_x, cur_y, right);
	}
	else if (cctv_num == 4)
	{
		move(cur_x, cur_y, left);
		move(cur_x, cur_y, dir);
		move(cur_x, cur_y, right);
	}
	else if (cctv_num == 5)
	{
		move(cur_x, cur_y, dir);
		move(cur_x, cur_y, left);
		move(cur_x, cur_y, right);
		move(cur_x, cur_y, opp);
	}
	
}

int calc()
{
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0)
				ret++;

	return ret;
}
void dfs(int cnt)
{
	
	int cur_x, cur_y, cctv_num;
	if (!q.empty())
	{
		cur_x = q[cnt - 1].first;
		cur_y = q[cnt - 1].second;
		cctv_num = q_num[cnt - 1];
	}
	
	for (int i = -1; i < 2; i++)//네방향 for문
			for (int j = -1; j < 2; j++)
				if (!(i == 0 && j == 0) && i * j == 0)
				{
					int check_size = temp.size();
					spread(cur_x, cur_y, i, j, cctv_num); //cctv 감시 함수
					if (cnt == num_camera)
					{
						if (_min > calc())// 사각지대 개수세기 함수
							_min = calc();
					}
					else //재귀
					{
						dfs(cnt + 1);
					}
					int end = temp.size() - check_size;
					for (int idx = 0; idx < end; idx++)
					{
						map[temp.back().first][temp.back().second] = 0;
						temp.pop_back();
					}
				}
}
int main()
{
	cin >> N >> M;
	for(int i = 0;i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5)
			{
				q.push_back(make_pair(i, j));
				q_num.push_back(map[i][j]);
			}
				
		}
	if(!q.empty())
		num_camera = q.size();

	dfs(1);
	cout << _min << endl;
	return 0;
}
