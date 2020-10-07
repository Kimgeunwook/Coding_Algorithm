//12:31����
#include <iostream>
#include <vector>
using namespace std;
int T, N, _max,sum;
vector<pair<int, int>> v[11];//��Ȧ
int arr[100][100];
int dx[4] = { -1, 0, 1, 0 }; //�� �� �� ��
int dy[4] = { 0, 1, 0, -1 };
int opp[4] = { 2, 3, 0, 1 };
int start_x, start_y;
int blockdir[6][4] = { //�ش� �������� ������ ���� ���� ���̴���
	{ 0,0,0,0 },
	{ 2,3,1,0 },
	{ 1,3,0,2 },
	{ 3,2,0,1 },
	{ 2,0,3,1 },
	{ 2,3,0,1 },
};
void input()
{
	for (int i = 0; i <= 10; i++) v[i].clear(); //��Ȧ���� �ʱ�ȭ
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (6 <= arr[i][j]) v[arr[i][j]].push_back({ i,j });
		}
			
	//���� �ʱ�ȭ
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

		if (arr[nextx][nexty] == -1 || (nextx == start_x && nexty == start_y))break; //��Ȧ or ���ڸ�
		else if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N)//������ ���϶�
		{
			sum++;
			dir = opp[dir];
		}
		else if (arr[nextx][nexty] >= 6)//��Ȧ ��������
		{
			pair<int, int> pa = warmhole(nextx, nexty);
			x = pa.first;
			y = pa.second;
			continue;
		}
		else if (1<=arr[nextx][nexty] && arr[nextx][nexty] <= 5) //��ϸ�������
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
		//cout << x << "," << y << "����" << i << "�������" << endl;
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