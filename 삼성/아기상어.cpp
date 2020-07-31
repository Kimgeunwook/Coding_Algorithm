#include <iostream>
#include <queue>
using namespace std;
struct info {
	int x, y, cnt;
};
struct compare {
	bool operator()(info a, info b)
	{
		if (a.x != b.x)
			return a.x > b.x;
		return a.y > b.y;
	}
};
priority_queue<info, vector<info>, compare> pq;
queue<info> q;
int N;
int map[20][20];
int current_size = 2; //상어 현재크기
int feed_size = 0; // 몇번 먹은지
int time = 0; //답
int flag = -1; 
int visit[20][20];
int now_x, now_y; //상어 현재 위치
void bfs()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = 0;

	int x, y, cnt;
	x = q.front().x;
	y = q.front().y;
	visit[x][y] = 1;

	while (!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		cnt = q.front().cnt;
	//	cout <<"x"<< x << "," <<"y"<< y << "," <<"cnt"<< cnt << "," << "진입" << endl;
		if (flag == -1 && cnt != 0 && map[x][y] != 0 &&map[x][y] < current_size) // 처음 플래그 바꿀때
		{
			//cout << "처음플래그바꿀"<<cnt << endl;
			flag = cnt;
			info final = { x, y, cnt };
			pq.push(final);
			q.pop();
			continue;
		}
		if (cnt == flag && map[x][y] != 0 && map[x][y] < current_size) //후보 추가
		{
			//cout << "후보 추가" << endl;
			info final = { x, y, cnt };
			pq.push(final);
			q.pop();
			continue;
		}
		if (flag != -1 && cnt > flag) //더이상볼필요 없는거
		{
			//cout << "더이상 볼필요 x" << endl;
			q.pop();
			continue;
		}
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				if( !(i == 0 && j == 0) && i * j == 0)
					if (x + i >= 0 && x + i < N && y + j >= 0 && y + j < N)
						if (visit[x + i][y + j] == 0 && map[x + i][y + j] <= current_size)
						{
							//cout << "캬" << endl;
							visit[x + i][y + j] = 1;
							info next = {x + i, y + j, cnt + 1};
							q.push(next);
						}

		q.pop();
	}
	if(flag == -1)
		return;
	time += flag;
	
	while (!q.empty())
	{
		q.pop();
	}
	if (!pq.empty())
	{
		map[now_x][now_y] = 0;
		now_x = pq.top().x;
		now_y = pq.top().y;
		info next = { now_x, now_y, 0};
		q.push(next);
		map[now_x][now_y] = 9;
	}
		
	while (!pq.empty())
	{
		pq.pop();
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
				info a = { i, j, 0 };
				q.push(a);
			}
		}
	now_x = q.front().x;
	now_y = q.front().y;

	while (1)
	{
		flag = -1;
		/*cout << "ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ" << endl;
		cout << "상어지금위치:" << now_x << "," << now_y << endl;
		cout << "time:" << time << endl;*/
		bfs();
		if (flag == -1)
			break;

		feed_size += 1;
		if (feed_size == current_size)
		{
			current_size += 1;
			feed_size = 0;
		}
	}
	cout << time << endl;
	return 0;
}
