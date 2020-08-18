#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
bool map[201][201];
int main()
{
	//input
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = true;
		}


	//get minimum path weight
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (map[i][k] && map[k][j]) map[i][j] = true;
			
	int cur = 0, next = 0;
	cin >> cur;
	for (int i = 1; i < M; i++)
	{
		cin >> next;
		if (next == cur) continue;
		if (map[cur][next] == false)
		{
			cout << "NO" << endl;
			return 0;
		}

		cur = next;
	}

	cout << "YES" << endl;
	return 0;
}