#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int N, M; //배열크기 남을치킨집수
int map[50][50];
int _min = 987654321;
int temp[13];
vector<pair<int, int>> chicken, house;
void dfs(int cnt, int idx)
{
	if (cnt == M)
	{
		int sum = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int temp_min =987654321;
			for (int j = 0; j < M; j++)
			{
				
				temp_min = min(temp_min, abs(house[i].first - chicken[temp[j]].first) + abs(house[i].second - chicken[temp[j]].second) );
			}
			sum += temp_min;
		}
		_min = min(_min, sum);
	}
	else
	{
		for (int i = idx; i < chicken.size(); i++)
		{
			temp[cnt] = i;
			dfs(cnt + 1, i + 1);
		}
	}
}
int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)//집
				house.push_back(make_pair(i, j));
			if (map[i][j] == 2) //치킨
				chicken.push_back(make_pair(i, j));
		}

	dfs(0, 0);
	cout << _min << endl;
	return 0;
}
