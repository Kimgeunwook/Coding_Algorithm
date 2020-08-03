#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;
int floyd[401][401];
vector<pair<int, int>> v;
int main()
{

	cin >> n >> k;
	int a, b;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		floyd[a][b] = -1;
		floyd[b][a] = 1;
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	for(int i = 1; i <= n ; i++)
		for(int start = 1; start <= n ;start++)
			for (int dest = 1; dest <= n; dest++)
			{
				if (floyd[start][i] == 1 && floyd[i][dest] == 1)
				{
					floyd[start][dest] = 1;
					floyd[dest][start] = -1;
				}	
				else if (floyd[start][i] == -1 && floyd[i][dest] == -1) {
					floyd[start][dest] = -1;
					floyd[dest][start] = 1;
				}
			}

	
	for (int i = 0; i < T; i++)
		cout << floyd[v[i].first][v[i].second] << "\n";
	return 0;
}