#include <iostream>
#include <queue>
using namespace std;
int N, M;
int map[301][301];
int temp[301][301];
bool visit[301][301];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
void deccount(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
		if (temp[x + dx[i]][y + dy[i]] == 0) cnt++;

	map[x][y] -= cnt;
	if (map[x][y] < 0) map[x][y] = 0;

}
int istwo() //1 : 아직 하나뭉치 , 2 : 두동강, 0:아예 빙산이없다 0출력
{
	int ans = 0;
	for (int i = 1; i < N; i++) 
		for (int j = 1; j < M; j++)
			if (!visit[i][j] && map[i][j] > 0)
			{
				ans++;
				q.push({ i,j });
				visit[i][j] = true;
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					
					for (int k = 0; k < 4; k++)
						if (map[x + dx[k]][y + dy[k]] > 0 && !visit[x + dx[k]][y + dy[k]])
						{
							visit[x + dx[k]][y + dy[k]] = true;
							q.push({ x + dx[k] , y + dy[k] });
						}
							
				}
			}
	return ans;
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
			

	int answer = 0;
	while (1)
	{
		answer++;
		for (int i = 0; i < N; i++) //맵 복사 & visit초기화
			for (int j = 0; j < M; j++)
			{
				temp[i][j] = map[i][j];
				visit[i][j] = false;
			}
				

		for (int i = 1; i < N; i++) //빙산 줄이기
			for (int j = 1; j < M; j++)
				if(map[i][j] != 0)
					deccount(i, j);

		int ret = istwo(); //몇 조각인지 검사
		if (ret > 1)
		{
			cout << answer << endl;
			return 0;
		}
		else if (ret == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		
	}
	return 0;
}