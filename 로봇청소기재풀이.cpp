#include <iostream>
using namespace std;
int N, M;
int curx, cury, dir; //로봇위치, 방향
int sum = 0;//정답 변수
int map[50][50] , visit[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void simulation()
{
	while (1)
	{
		int flag = 0;
		for (int i = 0; i < 4; i++) //4방향 회전
		{
			int next_dir = (dir + 3) % 4; // 왼쪽으로 회전
			dir = next_dir;
			if (map[curx + dx[dir]][cury + dy[dir]] == 0 && visit[curx + dx[dir]][cury + dy[dir]] == 0)//빈칸이고 안가본곳이면
			{
				flag++;
				visit[curx + dx[dir]][cury + dy[dir]] = 1;
				map[curx + dx[dir]][cury + dy[dir]] == 2; // 청소로 체크
				sum++;
				curx += dx[dir];
				cury += dy[dir];
				break;
			}
		}
		if (flag == 0) //갈곳없으면
		{
			if (curx - dx[dir] >= 0 && curx - dx[dir] < N && cury - dy[dir] >= 0 && cury - dy[dir] < M && map[curx - dx[dir]][cury - dy[dir]] != 1)//후진할수있으면
			{
				curx -= dx[dir];
				cury -= dy[dir];
			}
			else
				break;
		}
		
	}
}
int main()
{
	cin >> N >> M;
	cin >> curx >> cury >> dir;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];


	
	map[curx][cury] = 2; //현재칸 청소
	sum++; // 청소개수 ++
	visit[curx][cury] = 1;// for 시작점visit

	simulation();
	cout << sum << endl;
	return 0;
}