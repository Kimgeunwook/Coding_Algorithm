#include <iostream>
#include <queue>
using namespace std;
struct FISH {
	int x, y, distance;
};
struct info {
	int x, y, cnt;
};
struct comp {
	bool operator()(FISH a, FISH b) {
		if (a.distance != b.distance)
		{
			return a.distance > b.distance;
		}
		else
		{
			if (a.x != b.x)
				return a.x > b.x;
			else
				return a.y > b.y;
			
		}
	}
};
int map[20][20], visit[20][20], N;
int cur_shark_size = 2;
int shark_x, shark_y;
int feed_count = 0;
int _min = 9876;
priority_queue<FISH, vector<FISH>, comp> pq;
queue<info> q;
void bfs()
{
	while (!q.empty())
	{
		info cur = q.front();
		if (cur.cnt > _min)
		{
			q.pop();
			return;
		}
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				if (!(i == 0 && j == 0) && (i * j == 0))
					if (cur.x + i >= 0 && cur.x + i < N && cur.y + j >= 0 && cur.y + j < N)
						if (visit[cur.x + i][cur.y + j] == 0 && map[cur.x + i][cur.y + j] <= cur_shark_size)
						{
							visit[cur.x + i][cur.y + j] = 1;
							info temp = { cur.x + i  , cur.y + j, cur.cnt + 1 };
							q.push(temp);
							if (map[cur.x + i][cur.y + j] < cur_shark_size && map[cur.x + i][cur.y + j] != 0) //먹을수 있는물고기고 빈칸이아니면
							{
								FISH a = { cur.x + i , cur.y + j , cur.cnt + 1 };
								if (cur.cnt + 1 < _min) _min = cur.cnt + 1;
								pq.push(a);
							}
							
						}
		q.pop();
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				shark_x = i;
				shark_y = j;
			}
		}


	int k = 0;
	while (1)
	{
		while (!pq.empty()) pq.pop();
		while (!q.empty()) q.pop();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visit[i][j] = 0;

		info temp = { shark_x, shark_y ,0 };
		_min = 9876;
		q.push(temp);
		map[shark_x][shark_y] = 0;
		visit[shark_x][shark_y] = 1;
		
		bfs(); 
		
		if (pq.size() == 0) break; //먹을수 있는 물고기X
		shark_x = pq.top().x;
		shark_y = pq.top().y;
		
		feed_count ++;
		if (feed_count == cur_shark_size)
		{
			cur_shark_size++;
			feed_count = 0;
		}

		k += _min;
	}
	
	cout << k << endl;
			
	return 0;
}
