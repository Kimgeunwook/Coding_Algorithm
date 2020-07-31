#include <iostream>
#include <vector>
#include <math.h>
struct home {
	int x, y;
};
using namespace std;
int T, N, M;//초기화 필요 X
int map[20][20];//초기화필요
vector<home> v;
int search(int x, int y, int n)
{
	int cost = n * n + (n - 1) * (n - 1);
	int ret = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (abs(v[i].x - x) + abs(v[i].y - y) < n) 
			ret ++;
	}
	if (ret * M - cost >= 0) return ret;
	else return -1;
}
int calc(int n)
{
	int ret, max = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			ret = search(i, j, n);
			if (ret > max) max = ret;
		}
	return max;
			
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int test = 1; test <= T; test++)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1)
				{
					home newbie = { i,j };
					v.push_back(newbie);
				}
			}
		int _max = 0;
		for (int i = 1; i <= N + 2; i++)
		{
			int ret;
			ret = calc(i);
			if (ret > _max) _max = ret;
		}
		cout<<"#"<<test<< " " << _max << endl;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				map[i][j] = 0;
		v.clear();
	}
	

	return 0;
}
/////구현 다 했는데 답찾는 형식이 최대 집의수 (비용이아님)
