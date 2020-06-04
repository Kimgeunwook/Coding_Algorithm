#include <iostream>
using namespace std;
int map[50][50], temp[50][50], R, C, T;
int robot_up, robot_down;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
void spread()
{
	for(int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (temp[i][j] > 0)
			{
				map[i][j] -= temp[i][j];
				int cnt = 0;
				for (int k = 0; k < 4; k++)
					if (i + dx[k] >= 0 && i + dx[k] < R && j + dy[k] >= 0 && j + dy[k] < C && map[i + dx[k]][j + dy[k]] != -1)
					{
						cnt++;
						map[i + dx[k]][j + dy[k]] += temp[i][j] / 5;
					}
				map[i][j] += temp[i][j] - cnt * (temp[i][j] / 5);
			}
	
}
void robot()
{
	//위쪽
	for (int i = robot_up - 1; i >= 1; i--)
		map[i][0] = map[i - 1][0];
	for (int i = 0; i < C - 1; i++)
		map[0][i] = map[0][i + 1];
	for (int i = 0; i < robot_up; i++)
		map[i][C - 1] = map[i + 1][C - 1];
	for (int i = C - 1; i >= 2; i--)
		map[robot_up][i] = map[robot_up][i - 1];
	map[robot_up][1] = 0;

	//아래쪽
	for (int i = robot_down + 1; i < R - 1; i++)
		map[i][0] = map[i + 1][0];
	for (int i = 0; i < C - 1; i++)
		map[R - 1][i] = map[R - 1][i + 1];
	for (int i = R - 1; i > robot_down; i--)
		map[i][C - 1] = map[i - 1][C - 1];
	for (int i = C - 1; i > 1; i--)
		map[robot_down][i] = map[robot_down][i - 1];
	map[robot_down][1] = 0;
}
int answer()
{
	int ret = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (map[i][j] > 0)
				ret += map[i][j];
	return ret;
}
int main()
{
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				robot_up = i - 1;
				robot_down = i;
			}
		}

	while (T--)
	{
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				temp[i][j] = map[i][j];

		/*for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		cout << "이동후" << endl;*/
		spread();
		robot();
		/*for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << endl;
		}*/
	}
	cout << answer() << endl;
	return 0;
}