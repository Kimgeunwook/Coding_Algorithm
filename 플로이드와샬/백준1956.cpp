#include <iostream>
using namespace std;
#include <algorithm>
int V, E;
#define INF  987654321;
int floyd[401][401];
int main()
{
	cin >> V >> E;
	
	for (int i = 1; i <= 400; i++)
		for (int j = 1; j <= 400; j++)
			floyd[i][j] = INF;

	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		floyd[a][b] = c;
	}

	for(int k = 1; k <= V; k++)
		for(int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			
	int _min = 987654321;
	for (int i = 1; i <= 400; i++)
		_min = min(_min, floyd[i][i]);

	if (_min == 987654321)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << _min << endl;
	return 0;
}
