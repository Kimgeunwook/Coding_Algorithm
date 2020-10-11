//11:53시작 //1232끝
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct info {
	int x, y, depth;
};
int N, K;
int map[8][8];
int _max = -1;
vector<pair<int, int>> height_max;
queue<info> q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void input()
{
	int cur_max = -1;
	height_max.clear();

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] > cur_max)
			{
				height_max.clear();
				height_max.push_back({ i,j });
				cur_max = map[i][j];
			}
			else if (map[i][j] == cur_max)
			{
				height_max.push_back({ i,j });
			}
		}
			
	_max = -1;
}
void bfs()
{
	while (!q.empty())
	{
		info cur = q.front();
		q.pop();

		if (_max < cur.depth)
		{
			_max = cur.depth; //최고치 경신
			
		}
	
		for (int i = 0; i < 4; i++)
		{

			int nextx = cur.x + dx[i];
			int nexty = cur.y + dy[i];

			if (nextx >= 0 && nextx < N && nexty >= 0 && nexty < N)
				if (map[cur.x][cur.y] > map[nextx][nexty])
				{
					q.push({ nextx, nexty, cur.depth + 1 });
				}

		}
	}
}
void setCut(int x, int y)
{
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 1; k <= K; k++)
			{
				if (i == x && j == y) break; //자기자신이면 통과
				map[i][j] -= k;
				q.push({ x,y,1 });
				bfs();
				map[i][j] += k; //백트래킹형식으로 map다시되돌리기
			}
		
}
void solve()
{
	for (int k = 0; k < height_max.size(); k++) //가장 높은봉우리 다 해보기
	{
		int x = height_max[k].first;
		int y = height_max[k].second;
		setCut(x, y); //깎을곳 정하고 bfs시작
	}
}
int main()
{
	int T; cin >> T;
	for (int i = 1; i <= T; i++)
	{
		input();
		solve();
		cout << "#" << i << " " << _max << endl;
	}
	return 0;
}