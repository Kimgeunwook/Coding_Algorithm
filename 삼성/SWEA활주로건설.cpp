//2112시작
#include <iostream>
using namespace std;
int N, X,sum;
int map[20][20],copymap[20][20];

void input()
{
	cin >> N >> X;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	sum = 0;
}
void directionChange()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			copymap[i][j] = map[i][j];

	for(int j = N -1;j>=0;j--)
		for (int i = 0; i < N; i++)
		{
			map[N - 1 - j][i] = copymap[i][j];
		}
}
void simulation()
{
	for (int i = 0; i < N; i++)
	{
		int cur = map[i][0];
		int continous = 1;
		for (int j = 1; j < N; j++)
		{
			if (abs(cur - map[i][j]) >= 2)
			{
				cout << abs(cur - map[i][j]) << endl;
				continous = -1;
				break;
			}

			if (map[i][j] == cur)
			{
				continous++;
			}
			else if (map[i][j] > cur)
			{
				if (continous < X)//못 올라가는경우
				{
					continous = -1;
					break;
				}
				else
				{
					continous = 1;
					cur = map[i][j];
				}
			}
			else if (map[i][j] < cur)
			{
				if (continous >= 0)
				{
					continous = -X + 1;
					cur = map[i][j];
				}
				else//연속하강
				{
					continous = -1;
					break;
				}
			}
		}

		if (continous >= 0)
		{
			cout << i << "줄" << endl;
			sum++;
		}
	}
}
void solve()
{
	simulation();
	cout << "방향첸지" << endl;
	directionChange();
	simulation();
}
int main()
{
	int T; cin >> T;
	for (int i = 1; i <= T; i++)
	{
		input();
		solve();
		cout << "#" << i << " " << sum << endl;
	}
	return 0;
}