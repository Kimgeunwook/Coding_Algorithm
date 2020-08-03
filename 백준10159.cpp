#include <iostream>
#include <algorithm>
using namespace std;
int floyd[101][101];
int N, M;
int main()
{
	cin >> N;
	cin >> M;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		floyd[a][b] = 1; //a가 b보다 무거움
		floyd[b][a] = -1;
	}
	for(int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (floyd[i][k] == 1 && floyd[k][j] == 1) floyd[i][j] = 1;
				if (floyd[i][k] == -1 && floyd[k][j] == -1) floyd[i][j] = -1;
			}

	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i == j) continue;
			if (floyd[i][j] == 0)
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}