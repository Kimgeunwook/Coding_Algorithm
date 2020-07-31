#include <iostream>
using namespace std;
int position[19][3][2] = {//15개 모양  3개 좌표((0,0)은 디폴트)  2개 x,y좌표
	{ { 0,1 },{ 0,2 },{ 0,3 } },
{ { 1,0 },{ 2,0 },{ 3,0 } },
{ { 0,1 },{ 1,0 },{ 1,1 } },
{ { 1,0 },{ 2,0 },{ 2,1 } },
{ { 0,1 },{ 0,2 },{ 1,0 } },
{ { 0,1 },{ 1,1 },{ 2,1 } },
{ { 1,0 },{ 1,-1 },{ 1,-2 } },
{ { 1,0 },{ 1,1 },{ 2,1 } },
{ { 0,-1 },{ 1,-1 },{ 1,-2 } },
{ { 0,1 },{ 0,2 },{ 1,1 } },
{ { 1,0 },{ 2,0 },{ 1,-1 } },
{ { 1,0 },{ 1,-1 },{ 1,1 } },
{ { 1,0 },{ 1,1 },{ 2,0 } },
{ { 1,0 },{ 2,0 },{ 2,-1 } },
{ { 0,1 },{ 0,2 },{ 1,2 } },
{ { 0,1 },{ 1,0 },{ 2,0 } },
{ { 1,0 },{ 1,1 },{ 1,2 } },
{ { 1,0 },{ 1,-1 },{ 2,-1 } },
{ { 0,1 },{ 1,1 },{ 1,2 } }
};
int map[501][501], N, M, _max = 0;
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			for (int k = 0; k < 19; k++)
			{
				if ((i + position[k][0][0] >= 1 && i + position[k][0][0] <= N) && (i + position[k][1][0] >= 1 && i + position[k][1][0] <= N) && (i + position[k][2][0] >= 1 && i + position[k][2][0] <= N))
					if ((j + position[k][0][1] >= 1 && j + position[k][0][1] <= M) && (j + position[k][1][1] >= 1 && j + position[k][1][1] <= M) && (j + position[k][2][1] >= 1 && j + position[k][2][1] <= M))
						if (map[i][j] + map[i + position[k][0][0]][j + position[k][0][1]] + map[i + position[k][1][0]][j + position[k][1][1]] + map[i + position[k][2][0]][j + position[k][2][1]] >_max)
							_max = map[i][j] + map[i + position[k][0][0]][j + position[k][0][1]] + map[i + position[k][1][0]][j + position[k][1][1]] + map[i + position[k][2][0]][j + position[k][2][1]];
			}
		}
	cout << _max;
	return 0;
}