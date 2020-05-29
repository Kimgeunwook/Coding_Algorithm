#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct info {
	int x, y, way;
};
int map[50][50];
int visit[50][50];
int N, M, SIZE;
vector<info> virus;
vector<info> temp;
queue<info> q;
int min_way = 987654321;
void bfs()
{
	int cur_x, cur_y,cur_way;
	int cur_max_way = 0; //지역변수에선 가장큰거 찾고 끝날때는 minway랑 비교
	while (!q.empty())
	{
		cur_x = q.front().x;
		cur_y = q.front().y;
		cur_way = q.front().way;
		//cout << q.front().x << "," << q.front().y << "," << q.front().way << endl;
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				if (!(i == 0 && j == 0) && (i * j == 0))
					if (cur_x + i >= 0 && cur_x + i < N && cur_y + j >= 0 && cur_y + j < N)
						if (visit[cur_x + i][cur_y + j] == 0 && (map[cur_x+ i][cur_y + j] == 0 || map[cur_x + i][cur_y + j] == 2))
						{
							if (cur_way + 1 >= min_way)
								continue;
							visit[cur_x + i][cur_y + j] = 1;

							if ((cur_way + 1 > cur_max_way) && map[cur_x + i][cur_y  + j] != 2)
								cur_max_way = cur_way + 1;
							
							info newbie = {cur_x + i, cur_y + j, cur_way + 1};
							q.push(newbie);
						}
		q.pop();
	}
	//빈칸 있는지 찾는거
	int flag = 0;
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] == 0 && visit[i][j] == 0)
				ret = 1;

	if (ret == 0)
		flag = 1;
	
	//빈칸 없을때만 최소값 체크
	if(flag == 1)
		if (cur_max_way < min_way)
		{
			min_way = cur_max_way;
		}
			
}

void dfs(int cnt)
{
	if (temp.size() == M)
	{
		//visit 배열 초기화
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visit[i][j] = 0;

		//q사용전 초기화
		while (!q.empty())
		{
			q.pop();
		}

		//q에 넣어주기
		for (int i = 0; i < M; i++)
		{
			visit[temp[i].x][temp[i].y] = 1;
			q.push(temp[i]);
		}
		//bfs시작
		bfs();
	}
	else
	{
		for (int i = cnt; i < SIZE; i++)
		{
			temp.push_back(virus[i]);
			dfs(i + 1);
			temp.pop_back();
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				info a = {i, j , 0};
				virus.push_back(a);
			}
				
		}

	SIZE = virus.size();
	dfs(0);
	if (min_way == 987654321)
	{
		cout << -1 << endl;
	}
	else
		cout << min_way << endl;
	return 0;
}