#include <iostream>
using namespace std;
bool map[1002][1002];
int map_count[1002][1002];
void add_count(int x, int y, int num)
{
	int a = num / 2;
	if (map[x][y] == 1)
	{
		map_count[x + 1][y] += a;
		map_count[x][y + 1] += num - a;
	}
	else
	{
		map_count[x][y + 1] += a;
		map_count[x + 1][y] += num - a;
	}
}
int main()
{
	int H, W, N;
	cin >> H >> W >> N;

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			cin >> map[i][j];

	map_count[1][1] = N - 1; //처음 몇번돌껀지 알려줘야함

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			add_count(i, j, map_count[i][j]);

	for (int i = 1; i <= H; i++) //N-1번 돌았을때 지도 상황
		for (int j = 1; j <= W; j++)
			if (map_count[i][j] % 2 == 1)
				map[i][j] = !map[i][j];

	int x = 1, y = 1;
	while (1) //N번째 돌면 도착지가 어딘지
	{
		if (map[x][y] == 1)
			y += 1;
		else if (map[x][y] == 0)
			x += 1;

		if (x == H + 1 || y == W + 1)
			break;
	}
	cout << x << " " << y << endl;
	return 0;
}