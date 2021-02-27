#include <iostream>
using namespace std;
int N, M, answer = 0;
bool map[501][501];
int main()
{
	cin >> N >> M;
	for (int k = 0; k < M; k++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = true;
	}

	for(int k = 1 ; k <= N ;k++)
		for(int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (map[i][k] && map[k][j]) map[i][j] = true;
			
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i == j) continue;
			if (map[i][j] == false && map[j][i] == false) { cnt++; } /*break;*/
			if (j == N) answer++;

		}
		if (cnt == 0)answer++;
	}
	cout << answer << endl;
	return 0;
}