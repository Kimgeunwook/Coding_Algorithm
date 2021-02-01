//2008 Ω√¿€
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321;
int map[501][501];
int tc, N, M, W, S, E, T;
void Input()
{
	cin >> N >> M >> W;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			map[i][j] = INF;

	for (int i = 0; i < M; i++)
	{
		cin >> S >> E >> T;
		map[S][E] = min(map[S][E], T);
		map[E][S] = min(map[E][S], T);
	}
	for (int i = 0; i < W; i++)
	{
		cin >> S >> E >> T;
		map[S][E] = min(map[S][E], -1 * T);
	}
}
int main()
{
	cin >> tc;
	while (tc--)
	{
		Input();
		for(int k = 1 ; k <= N ; k++)
			for(int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
				
		bool flag = false;
		for (int i = 1; i <= N; i++)
		{
			if (map[i][i] < 0)
			{
				flag = true;
				cout << "YES" << endl;
				break;
			}
		}
		if (!flag) cout << "NO" << endl;
	}
	return 0;
}