//1331시작
#include <iostream>
#include <queue>
using namespace std;
int K, N, M, R, C, L, answer;
int dx[4] = { -1 , 0, 1, 0 }, dy[4] = { 0 , 1, 0, -1 };
int map[50][50];
bool visit[50][50];
struct info {
	int r, c, time;
};
queue<info> q;
int opp[4] = { 2, 3, 0, 1 };
bool root[8][4] = {
	{ false, false, false, false },
{ true, true, true, true },
{ true, false, true, false },
{ false, true, false, true },
{ true, true, false ,false },
{ false, true, true, false },
{ false, false, true, true },
{ true, false, false, true },
};
void Input()
{
	cin >> N >> M >> R >> C >> L;
	for (int a = 0; a < 50; a++)
		for (int b = 0; b < 50; b++)
		{
			map[a][b] = 0;
			visit[a][b] = false;
		}
	for (int a = 0; a < N; a++)
		for (int b = 0; b < M; b++)
		{
			cin >> map[a][b];
			visit[a][b] = false;
		}
	info temp = { R, C, 1 };
	q.push(temp);
	visit[R][C] = true;
	answer = 1;
}
void bfs()
{
	while (!q.empty())
	{
		info cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int t_Num = map[cur.r][cur.c];//현재 있는자리가 몇번터널인지
			int next_t_NUM = map[cur.r + dx[i]][cur.c + dy[i]];//이동할자리가 몇번터널인지
			if (root[t_Num][i] && root[next_t_NUM][opp[i]]) // 둘이 이어져있으면
			{
				if (!visit[cur.r + dx[i]][cur.c + dy[i]] && cur.time < L)
				{
					visit[cur.r + dx[i]][cur.c + dy[i]] = true;
					answer++;
					info newbie = { cur.r + dx[i] , cur.c + dy[i] , cur.time + 1 };
					q.push(newbie);
				}
			}
		}


	}
}
int main() {
	cin >> K;

	for (int i = 1; i <= K; i++)
	{
		Input();
		bfs();
		cout << "#" << i << " " << answer << endl;
	}
	return 0;
}