//1839시작
#include <iostream>
#include <vector>
using namespace std;
int T, D, W, K;
int _min;//몇개 바꾼지, 정답
int map[13][20];
int copymap[13][20];
int temp[13];
int cur_howmany = 0;
void input()
{
	cin >> D >> W >> K;
	for (int i = 0; i < D; i++)
		for (int j = 0; j < W; j++)
		{
			cin >> map[i][j];
		}
	cur_howmany = 0;
	_min = 987654321;
}
bool isPerfect()
{
	for (int j = 0; j < W; j++)
	{
		bool flag = true; //마지막까지 true면 연속된게 없는줄
		int continuous = 1; //몇개 연속된지
		int cur = copymap[0][j]; //지금 현재 숫자가 뭔지
		for (int i = 1; i < D; i++)
		{
			if (cur == copymap[i][j])
			{
				continuous++;
				if (continuous >= K)
				{
					flag = false;
					break;
				}
			}
			else
			{
				continuous = 1;
				cur = copymap[i][j];
			}
		}
		if (flag) return false;
	}
	return true;
}
void makeTozero(int idx)
{
	for (int i = 0; i < W; i++)
		copymap[idx][i] = 0;
}
void makeToone(int idx)
{
	for (int i = 0; i < W; i++)
		copymap[idx][i] = 1;
}
void dfs(int cnt)
{
	if (cnt == D)
	{
		int num = 0;

		for (int i = 0; i < D; i++)
			for (int j = 0; j < W; j++)
				copymap[i][j] = map[i][j];

		for (int i = 0; i < D; i++)
		{
			if (temp[i] == 1)
			{
				num++;
				makeToone(i);
			}
			else if (temp[i] == 2)
			{
				num++;
				makeTozero(i);
			}
		}

		if (isPerfect())
			if (_min > num) _min = num;

	}
	else
	{
		for (int k = 0; k < 3; k++)
		{
			temp[cnt] = k;
			if (k != 0) cur_howmany++;
			if (cur_howmany >= _min)
			{
				cur_howmany--;
				continue;
			}
			dfs(cnt + 1);
			if (k != 0) cur_howmany--;
		}
	}
}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		input();
		if (K == 1)
		{
			cout << "#" << i << " " << 0 << endl;
			continue;
		}
		dfs(0);
		cout << "#" << i << " " << _min << endl;
	}
	return 0;
}