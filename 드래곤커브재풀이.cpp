#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<int> temp;
int map[101][101];
int N;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int main()
{
	cin >> N;
	int y, x, d, g;
	for (int i = 0; i < N; i++)
	{
		cin >> y >> x >> d >> g;

		v.clear();
		v.push_back(d);
		map[x][y] = 1;
		for (int generation = 1; generation <= g; generation++)
		{
			temp = v;
			reverse(temp.begin(), temp.end());
			for (int k = 0; k < temp.size(); k++)
				v.push_back((temp[k] + 1) % 4);
		}
		for (int k = 0; k < v.size(); k++)
		{
			x += dx[v[k]];
			y += dy[v[k]];
			map[x][y] = 1;
		}
	}
		
	int ret = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
				ret++;
	cout << ret << endl;
			
	return 0;
}