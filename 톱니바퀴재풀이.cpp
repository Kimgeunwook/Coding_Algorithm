#include <iostream>
using namespace std;
int map[5][8];
int same[4]; //같으면 1 다르면0
int visit[5];
void rotate(int n, int dir)
{
	int temp;
	if (visit[n] == 1 || n == 0 || n == 5)
		return;
	visit[n] = 1;
	if (dir == 1)//시계
	{
		temp = map[n][7];
		for (int i = 7; i >= 1; i--)
			map[n][i] = map[n][i - 1];
		map[n][0] = temp;
	}
	else
	{
		temp = map[n][0];
		for (int i = 0; i < 7; i++)
			map[n][i] = map[n][i + 1];
		map[n][7] = temp;
	}
		if (same[n - 1] == 0) rotate(n - 1, dir* -1);
		if (same[n] == 0) rotate(n + 1, dir * -1);
	
	
}
void simulation(int n, int dir)
{
	if (map[1][2] == map[2][6]) same[1] = 1;
	if (map[2][2] == map[3][6]) same[2] = 1;
	if (map[3][2] == map[4][6]) same[3] = 1;
	for (int i = 1; i <= 4; i++)
		visit[i] = 0;
	rotate(n, dir);
}
int main()
{
	for (int i = 1; i <= 4; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &map[i][j]);
	
	int N, n,dir;
	cin >> N ;
	for (int i = 0; i < N; i++)
	{
		cin >> n >> dir;
		for (int k = 0; k < 4; k++)
			same[k] = 0;
		simulation(n, dir);
	}
		
	cout << map[1][0] * 1 + map[2][0] * 2 + map[3][0] * 4 + map[4][0] * 8 << endl;
	return 0;
}