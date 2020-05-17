#include <iostream>
#include <vector>
using namespace std;
struct info
{
	int x, y, direct;
};
int opposite_dir[4] = {2, 3, 0, 1};
int map[50][50];
int dir[2][4] = { { -1, 0, 1, 0 },{ 0, 1, 0, -1 } }; //ºÏ 0   µ¿ 1   ³² 2  ¼­ 3
int N, M;
vector<info> v;
int calc()
{
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 2)
				ret++;
	return ret;
}
int set_dir(int n, int m)
{
	if (n - m < 0)
	{
		return 4 - (m - n);
	}
	else {
		return n - m;
	}
}
void dfs()
{
	while (!v.empty())
	{
		int _cnt = 0;
		for (int i = 1; i <= 4; i++)
		{
			int cur_x = v.back().x;
			int cur_y = v.back().y;
			int cur_dir = set_dir(v.back().direct, i);
			if (map[cur_x + dir[0][cur_dir]][cur_y + dir[1][cur_dir]] == 0)
			{
				map[cur_x + dir[0][cur_dir]][cur_y + dir[1][cur_dir]] = 2;
				info next;
				next = { cur_x + dir[0][cur_dir], cur_y + dir[1][cur_dir], cur_dir };
				v.push_back(next);
				break;
			}
			else {
				_cnt++;
			}
		
			if (_cnt == 4)
			{
				if (map[cur_x - dir[0][cur_dir]][cur_y - dir[1][cur_dir]] != 1) //ºóÄ­ÀÌ¸é
				{
					info next;
					next = { cur_x - dir[0][cur_dir], cur_y - dir[1][cur_dir], cur_dir };
					v.push_back(next);
					break;
				}
				else { //º®ÀÌ¸é
					return;
				}
			}
				
		}
	}
}
int main()
{
	int first_x, first_y, first_dir; //Ã³À½ ·Îº¿ x, y, ¹æÇâ
	info first;

	cin >> N >> M;
	cin >> first_x >> first_y >> first_dir;
	first = { first_x, first_y, first_dir };
	v.push_back(first);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	
	map[first_x][first_y] = 2;
	dfs();
	cout<< calc() <<endl;
}