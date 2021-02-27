//1816시작
#include <iostream>
#include <queue>
using namespace std;
int map[100][100];
bool visit[100][100];
int N, M;
queue<pair<int, int>> q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
}
void bfs()
{
	while (!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (curx + dx[i] >= 0 && curx + dx[i] < N && cury + dy[i] >= 0 && cury + dy[i] < M)
				if (!visit[curx + dx[i]][cury + dy[i]] && map[curx + dx[i]][cury + dy[i]] == 0)
				{
					visit[curx + dx[i]][cury + dy[i]] = true;
					q.push({ curx + dx[i], cury + dy[i] });
				}
		}

	}
}
void fill()
{
	for (int i = 0; i < N; i++)
	{
		if (!visit[i][0] && map[i][0] == 0)
		{
			q.push({ i, 0 });
			visit[i][0] = true;
			bfs();
		}
		if (!visit[i][M - 1] && map[i][M -1] == 0)
		{
			q.push({ i, M - 1 });
			visit[i][M - 1] = true;
			bfs();
		}
	}
	for (int j = 0; j < M; j++)
	{
		if (!visit[0][j] && map[0][j] == 0)
		{
			q.push({ 0, j });
			visit[0][j] = true;
			bfs();
		}
		if (!visit[N - 1][j] && map[N -1][j] == 0)
		{
			q.push({ N - 1, j });
			visit[N - 1][j] = true;
			bfs();
		}
	}
}
void simulation()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 1)
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
					if (visit[i + dx[k]][j + dy[k]])cnt++;
				if (cnt >= 2) map[i][j] = 0;
			}
}
bool search()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 1) return false;

	return true;
}
int main()
{
	Input();

	int ans = 0;
	while (1)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				visit[i][j] = false;
				
		ans++;

		fill(); //겉부분 채우기 
		simulation(); //녹는치즈 없애기
		if (search()) break; //종료조건
	}
	cout << ans << endl;
	return 0;
}