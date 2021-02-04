//1.  bfs를 할때 묶음 단위로 움직이려면
//    현재 묶음의 크기만큼 한사이클로 돌기

//2. 맵의 형태가 커지면 visit배열의 역할도 중요함
//   일단 무조건 visit만들어서 어디에 넣을지 생각
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 987654321
int arr[100][100], section[100][100];
bool visit[100][100];
int N, sectNum = 1, answer = INF;
int dx[4] = { -1, 0 , 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue< pair<int, int>> q;
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
}
void bfs(int num)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (section[i][j] == num)
				q.push({ i,j });
			

	int depth = 0;
	while (!q.empty())
	{
		//영역을 확장하기 위해 한사이클 길이는 현재 땅의 크기만큼 만들어야함
		int size = q.size();
		for (int k = 0; k < size; k++)
		{
			int curx = q.front().first;
			int cury = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = curx + dx[i];
				int ny = cury + dy[i];
				int nx_sect = section[nx][ny];

				if (nx >= 0 && ny >= 0 && nx < N && ny < N)
				{
					// 다른 구역섬 만나면
					if (nx_sect != num && nx_sect > 0)
					{
						answer = min(answer, depth);
						return;
					}
					//바다 && 방문하지 않은곳이면
					if (arr[nx][ny] == 0 && !visit[nx][ny])
					{
						visit[nx][ny] = true;
						q.push({ nx, ny });
					}	
				}
			}
		}
		
		depth++;

	}
}

void dfs(int x, int y)
{
	section[x][y] = sectNum;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			if (arr[nx][ny] == 1 && section[nx][ny] == 0)
				dfs(nx, ny);

	}
}

//각 육지마다 번호 붙여주기
void sectioning()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (arr[i][j] == 1 && section[i][j] == 0)
			{
				dfs(i, j);
				sectNum++;
			}

}
void solve()
{
	for (int i = 1; i < sectNum; i++)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visit[i][j] = false;
		while (!q.empty()) q.pop();
		bfs(i);
	}
		
}
int main()
{
	input();
	sectioning();//섬 구역 나누기
	solve();
	cout << answer << endl;
	return 0;
}