#include <iostream>
#include <queue>
using namespace std;
queue<int> location_x, location_y;
int N, map_size, current_x, current_y, object_x, object_y, answer_flag = 0;
bool visit[301][301], map[301][301];
int depth[301][301];
int arr_y1[2] = { -1,1 };
int arr_y2[2] = { -2,2 };
void bfs(int x, int y)
{
	if (x == object_x && y == object_y)
		answer_flag = 1;
	location_x.pop();
	location_y.pop();
	visit[x][y] = 1;

	for (int i = -2; i <= 2; i++)
	{
		if (i != 0)
		{
			if (i == -2 || i == 2)
			{
				for (int j = 0; j < 2; j++)
					if (x + i >= 0 && x + i < map_size&& y + arr_y1[j] >= 0 && y + arr_y1[j]<map_size)
						if (visit[x + i][y + arr_y1[j]] == 0)
						{
							depth[x + i][y + arr_y1[j]] = depth[x][y] + 1;
							location_x.push(x + i);
							location_y.push(y + arr_y1[j]);
							visit[x + i][y + arr_y1[j]] = 1;
						}
			}
			else
			{
				for (int j = 0; j < 2; j++)
					if (x + i >= 0 && x + i < map_size&& y + arr_y2[j] >= 0 && y + arr_y2[j]<map_size)
						if (visit[x + i][y + arr_y2[j]] == 0)
						{
							depth[x + i][y + arr_y2[j]] = depth[x][y] + 1;
							location_x.push(x + i);
							location_y.push(y + arr_y2[j]);
							visit[x + i][y + arr_y2[j]] = 1;
						}
			}
		}
	}

}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> map_size;
		cin >> current_x >> current_y;
		cin >> object_x >> object_y;
		////////////////////
		location_x.push(current_x);
		location_y.push(current_y);
		//////////////////////
		while (!location_x.empty())
		{
			bfs(location_x.front(), location_y.front());
			if (answer_flag == 1)
			{
				answer_flag = 0;
				cout << depth[object_x][object_y] << endl;
				break;
			}
		}
		/////////////////////
		while (!location_x.empty())
		{
			location_x.pop();
			location_y.pop();
		}
		for (int i = 0; i<map_size; i++)
			for (int j = 0; j < map_size; j++)
			{
				depth[i][j] = 0;
				visit[i][j] = 0;
			}
	}
	return 0;
}