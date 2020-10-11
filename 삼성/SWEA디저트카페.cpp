//0750시작
#include <iostream>
using namespace std;
bool visit[101];
int map[20][20];
int N, _max;
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	_max = -1;

}
int getAns(int x, int y, int width, int height)
{
	int cnt = 0;
	for (int i = 0; i <= width; i++) //북->서
	{
		if (!visit[map[x + i][y - i]])
		{
			visit[map[x + i][y - i]] = true;
			cnt++;
		}
		else
			return -1;
	}
	for (int i = 1; i <= height - width; i++) //서->남
	{
		if (!visit[map[x + width + i][y - width + i]])
		{
			visit[map[x + width + i][y - width + i]] = true;
			cnt++;
		}
		else
			return -1;
	}
	for (int i = 1; i < width; i++)//남->동
	{
		if (!visit[map[x + height - i][y + height - 2 * width + i]])
		{
			visit[map[x + height - i][y + height - 2 * width + i]] = true;
			cnt++;
		}
		else
			return -1;
	}
	for (int i = 1; i <= height - width; i++) //북->동
	{
		if (!visit[map[x + i][y + i]])
		{
			visit[map[x + i][y + i]] = true;
			cnt++;
		}
		else
			return -1;
	}
	return cnt ; 
		
}
void simulation(int x, int y)
{
	for (int height = 2; height < N - x; height++) //heigth == 아래로 얼마만큼갔냐
	{
		for (int width = 1; width < height; width++)//width == 옆으로 얼마만큼갔냐
		{
			if (y - width < 0 || y + (height - width) >= N || x + height >= N) continue; //범위 넘어가는거 체크
			for (int i = 0; i <= 100; i++)visit[i] = false; 
			int ret = getAns(x, y, width, height);
			if (ret > _max) _max = ret;
		}
	}
}
void solve()
{
	for(int i = 0; i < N - 2; i++)
		for (int j = 1; j <= N - 2; j++)
		{
			simulation(i, j);
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