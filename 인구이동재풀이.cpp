#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int map[50][50], visit[50][50];
int N, L, R;
int answer;
int sum;
vector<pair<int,int>> v;
void average()
{
	int average = sum / v.size();
	for (int i = 0; i < v.size(); i++)
		map[v[i].first][v[i].second] = average;
}
void dfs(int x, int y)
{
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (!(i == 0 && j == 0) && (i * j == 0))
				if (x + i >= 0 && x + i < N && y + j >= 0 && y + j < N)
					if (visit[x + i][y + j] == 0 && L <= abs(map[x][y] - map[x + i][y + j]) && abs(map[x][y] - map[x + i][y + j]) <= R)
					{
						visit[x + i][y + j] = 1;
						sum += map[x + i][y + j];
						v.push_back(make_pair(x + i, y + j));
						dfs(x + i, y + j);
					}
					
}
int simulation()
{
	for (int i = 0; i < N; i++) //visit배열 초기화
		for (int j = 0; j < N; j++)
			visit[i][j] = 0;

	int flag = 0;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (visit[i][j] == 0)
			{
				v.clear();
				sum = map[i][j];
				v.push_back(make_pair(i, j));
				visit[i][j] = 1;
				dfs(i, j);
				if (v.size() >= 2)
					flag = 1;
				average();
			}
	
	if (flag == 1)
		return 1;
	else
		return -1;
}
int main()
{
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	while (1)
	{
		int ret = simulation();

		if (ret == -1) // 이동 없었으면
			break;
		answer++;
	}
	cout << answer << endl;
	return 0;
}