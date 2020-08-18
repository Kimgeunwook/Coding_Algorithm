//21:40½ÃÀÛ

#include <iostream>
#include <algorithm>
using namespace std;
int N, M ,X;
int arr[1001][1001];
#define INF 987654321
int main()
{
	cin >> N >> M >> X;
	int start, dest, weight;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			arr[i][j] = INF;

	for (int i = 0; i < M; i++)
	{
		cin >> start >> dest >> weight;
		arr[start][dest] = weight;
	}

	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}

	int _max = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i == X) continue;
		if (_max < arr[i][X] + arr[X][i]) _max = arr[i][X] + arr[X][i];
	}
	cout << _max << endl;
	return 0;
}
