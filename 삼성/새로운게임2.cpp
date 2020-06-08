#include <iostream>
#include <vector>
using namespace std;
struct HORSE
{
	int x, y, dir,original, cnt; // 좌표 / 방향 / 첨에 몇번째였는지 /거기서 몇번째인지
};
int N,K;
int map[12][12];
vector<HORSE> h;
vector<HORSE> v[12][12];
int visit[12][12];
int simulation()
{
	
	int flag_dir = 0;
	for (int k = 0; k < K; k++)
	{
		HORSE cur = h[k];

		int dx , dy;
		if (cur.dir == 1)
		{
			dx = 0;
			dy = 1;
		}
		else if (cur.dir == 2)
		{
			dx = 0;
			dy = -1;
		}
		else if (cur.dir == 3)
		{
			dx = -1;
			dy = 0;
		}
		else if (cur.dir == 4)
		{
			dx = 1;
			dy = 0;
		}

		if (cur.x + dx >= 0 && cur.x + dx < N && cur.y + dy >= 0 && cur.y + dy < N)
		{
			int SIZE = v[cur.x][cur.y].size() - cur.cnt; //옮겨야 하는 개수
			if (map[cur.x + dx][cur.y + dy] == 0)
			{
				for (int a = cur.cnt; a < v[cur.x][cur.y].size(); a++)
				{
					h[v[cur.x][cur.y][a].original].cnt = v[cur.x + dx][cur.y + dy].size();
					h[v[cur.x][cur.y][a].original].x = cur.x + dx;
					h[v[cur.x][cur.y][a].original].y = cur.y + dy;
					v[cur.x + dx][cur.y + dy].push_back(v[cur.x][cur.y][a]);
					if (v[cur.x + dx][cur.y + dy].size() >= 4)
						return 1;
				}
				for (int a = 0; a < SIZE; a++)
					v[cur.x][cur.y].pop_back();
				if (visit[cur.x][cur.y] == 1)
					visit[cur.x][cur.y] = 0;
			}
			else if (map[cur.x + dx][cur.y + dy] == 1)
			{
				for (int a = v[cur.x][cur.y].size() - 1; a  >= cur.cnt; a--)
				{
					h[v[cur.x][cur.y][a].original].cnt = v[cur.x + dx][cur.y + dy].size();
					h[v[cur.x][cur.y][a].original].x = cur.x + dx;
					h[v[cur.x][cur.y][a].original].y = cur.y + dy;
					v[cur.x + dx][cur.y + dy].push_back(v[cur.x][cur.y][a]);
					if (v[cur.x + dx][cur.y + dy].size() >= 4)
						return 1;
				}
				for (int a = 0; a < SIZE; a++)
					v[cur.x][cur.y].pop_back();
				if (visit[cur.x][cur.y] == 1)
					visit[cur.x][cur.y] = 0;
			}
			else if (map[cur.x + dx][cur.y + dy] == 2)
			{
				//방향 반대로 해주고
				if (visit[cur.x][cur.y] == 0)
				{
					visit[cur.x][cur.y] = 1;
					if (cur.dir == 1)
						h[k].dir = 2;
					else if (cur.dir == 2)
						h[k].dir = 1;
					else if (cur.dir == 3)
						h[k].dir = 4;
					else if (cur.dir == 4)
						h[k].dir = 3;
					k--;
				}				
				else
					visit[cur.x][cur.y] = 0;

			}
		}
		else
		{
			if (visit[cur.x][cur.y] == 0)
			{
				visit[cur.x][cur.y] = 1;
				if (cur.dir == 1)
					h[k].dir = 2;
				else if (cur.dir == 2)
					h[k].dir = 1;
				else if (cur.dir == 3)
					h[k].dir = 4;
				else if (cur.dir == 4)
					h[k].dir = 3;
				k--;
			}
			else
				visit[cur.x][cur.y] = 0;
		}
	}

	
	return 0;
}
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < K; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		HORSE temp = { a - 1, b - 1, c, i , 0};
		h.push_back(temp);
		v[a-1][b-1].push_back(temp);
	}

	int ret = 1;
	int flag = 0;

	while (ret <= 1000)
	{
		//cout << "시뮬" << endl;
		//시뮬돌리고
		flag = simulation();

		//4개 얹혀서 끝났으면 ret 출력
		if (flag == 1)
		{
			cout << ret << endl;
			return 0;
		}
		//아니면 ret++
		ret++;
	}
	//ret이 1000넘어서 끝났으면 -1출력
	cout << -1 << endl;
	return 0;
}
