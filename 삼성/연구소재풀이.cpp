#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int map[8][8];
int fmap[8][8];
int visit[8][8];
pair<int,int> temp[3];
vector<pair<int,int>> v;
queue<pair<int, int>> virus, virus_temp;
int _max = -987654321;
void simulation()
{

	while (!virus_temp.empty())
	{
		int curx = virus_temp.front().first;
		int cury = virus_temp.front().second;
		
		
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
			{
				if (!(i == 0 && j == 0) && (i * j == 0))
				{
					if (curx + i >= 0 && curx + i < N && cury + j >= 0 && cury + j < M)
						if (visit[curx + i][cury + j] == 0 && fmap[curx + i][cury + j] != 1)
						{
							visit[curx + i][cury + j] = 1;
							fmap[curx + i][cury + j] = 2;
							virus_temp.push(make_pair(curx + i, cury + j));
						}
				}
			}
		virus_temp.pop();
	}
}
int answer() {
	int ret = 0; 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (fmap[i][j] == 0)
				ret++;
	return ret;
}
int sum = 0;
void dfs(int cnt,int idx)
{
	if (cnt == 3)
	{
		for (int a = 0; a < N; a++) //¸Êº¹»ç
			for (int b = 0; b < M; b++)
			{
				visit[a][b] = 0;
				fmap[a][b] = map[a][b];
			}
				
		for (int a = 0; a < 3; a++) //º®¼¼¿ì±â
		{
			fmap[temp[a].first][temp[a].second] = 1;
		}
		virus_temp = virus;
		visit[virus_temp.front().first][virus_temp.front().second] = 1;
		simulation();
			
		int ret = answer();
		if (ret > _max)
			_max = ret;
	}
	else
	{
		for (int i = idx; i < v.size(); i++)
		{
			temp[cnt] = v[i];
			dfs(cnt + 1, i + 1);
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
				v.push_back(make_pair(i,j));
			if (map[i][j] == 2)
				virus.push(make_pair(i, j));
		}
	dfs(0,0);
	printf("%d", _max);
	return 0;
}
