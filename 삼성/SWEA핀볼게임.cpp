//12:31시작
#include <iostream>
#include <vector>
using namespace std;
int T, N, _max,sum;
vector<pair<int, int>> v[11];//웜홀
int arr[100][100];
int dx[4] = { -1, 0, 1, 0 }; //북 동 남 서
int dy[4] = { 0, 1, 0, -1 };
int opp[4] = { 2, 3, 0, 1 };
int start_x, start_y;
int blockdir[6][4] = { //해당 방향으로 갔을때 방향 어디로 꺾이는지
	{ 0,0,0,0 },
	{ 2,3,1,0 },
	{ 1,3,0,2 },
	{ 3,2,0,1 },
	{ 2,0,3,1 },
	{ 2,3,0,1 },
};
void input()
{
	for (int i = 0; i <= 10; i++) v[i].clear(); //웜홀벡터 초기화
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (6 <= arr[i][j]) v[arr[i][j]].push_back({ i,j });
		}
			
	//각종 초기화
	_max = 0;
}
pair<int, int> warmhole(int x, int y)
{
	for (int k = 0; k < 2; k++)
	{
		if (v[arr[x][y]][k].first != x || v[arr[x][y]][k].second != y)
		{
			return make_pair(v[arr[x][y]][k].first, v[arr[x][y]][k].second);
		}
	}
}
void play(int x, int y, int dir)
{
	while (1)
	{
		//cout <<x << ","<<y << endl;
		int nextx = x + dx[dir];
		int nexty = y + dy[dir];

		if (arr[nextx][nexty] == -1 || (nextx == start_x && nexty == start_y))break; //블랙홀 or 제자리
		else if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N)//다음이 벽일때
		{
			sum++;
			dir = opp[dir];
		}
		else if (arr[nextx][nexty] >= 6)//웜홀 만났을때
		{
			pair<int, int> pa = warmhole(nextx, nexty);
			x = pa.first;
			y = pa.second;
			continue;
		}
		else if (1<=arr[nextx][nexty] && arr[nextx][nexty] <= 5) //블록만났을때
		{
			sum++;
			dir = blockdir[arr[nextx][nexty]][dir];
		}
		x = nextx;
		y = nexty;

	}
	
}
void check(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		//cout << x << "," << y << "에서" << i << "방향시작" << endl;
		sum = 0;
		start_x = x;
		start_y = y;
		play(x, y, i);
		if (sum > _max)_max = sum;
	}
		
}
void solve()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (arr[i][j] == 0)
				check(i, j);
}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		input();
		solve();
		cout << "#" << i << " " << _max << endl;
	}
	return 0;
}