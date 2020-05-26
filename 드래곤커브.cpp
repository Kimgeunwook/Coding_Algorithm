#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
struct info {
	int x, y, dir, gen;
};
int N;
int map[101][101];
int dy[4] = {0 , -1, 0, 1};
int dx[4] = {1, 0, -1, 0}; //동 북 서 남

vector<info> v;
void simul()
{
	vector<int> v_cur;
	vector<int> temp;
	for (int i = 0; i < v.size(); i++) //입력 개수 만큼
	{
		v_cur.clear();
		temp.clear();
		v_cur.push_back(v[i].dir); //처음 방향은 넣어주기

		int cur_y = v[i].y, cur_x = v[i].x;
		map[cur_y][cur_x] = 1;
		for (int j = 0; j <= v[i].gen; j++) //몇세대 만큼 반복할지
		{
			int f;
			if (j) f = pow(2, j - 1);
			else f = 0;
			for (int k = f; k < v_cur.size(); k++)
			{
				if (cur_y + dy[v_cur[k]] > 100)
					cout << "sjaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
				map[cur_y + dy[v_cur[k]]][cur_x + dx[v_cur[k]]] = 1;
				cur_y += dy[v_cur[k]];
				cur_x += dx[v_cur[k]];
			}
			temp = v_cur;
			reverse(temp.begin(), temp.end());
			for (int p = 0; p < temp.size(); p++)
			{
				v_cur.push_back((temp[p] + 1)%4);
			}
		}
	}
	
}
int get_ans()
{
	int ret = 0;
	for(int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				ret++;
		}
	return ret;
}
int main()
{
	cin >> N;
	int input_x, input_y, input_dir, input_gen;
	info cur;
	for (int i = 0; i < N; i++)
	{
		cin >> input_x >> input_y >> input_dir >> input_gen;
		cur = { input_x , input_y, input_dir, input_gen };
		v.push_back(cur);
	}
	simul();
	cout << get_ans() << endl;
	return 0;
}