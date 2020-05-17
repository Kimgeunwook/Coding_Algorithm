#include <iostream>
#include <vector>
using namespace std;
char map[12][6];
bool visit[12][6];
vector<pair<int,int>> v;
int cur_v_size = 0 , change_v_size = 0;
int flag = 0, entire_flag = 0;
void calc(int cur_x, int cur_y, char cur_char)
{
	
	v.push_back(make_pair(cur_x,cur_y));
	visit[cur_x][cur_y] = 1;
	for(int i = -1; i < 2; i++)
		for(int j = -1;j < 2; j++)
			if (!(i == 0 && j == 0) && i * j == 0) //4방향 탐색
				if (cur_x + i >= 0 && cur_x + i < 12 && cur_y + j >= 0 && cur_y + j < 6 && visit[cur_x + i][cur_y + j] == 0)
					if (map[cur_x + i][cur_y + j] == cur_char)
					{
						calc(cur_x + i, cur_y + j, cur_char);
					}
}
void pull_down()
{
	for(int i = 10; i >= 0 ;i--)
		for (int j = 0; j < 6; j++)
		{
			if (map[i][j] == '.')
				continue;
			int k;
			for (k = 1; ; k++)
			{
				if (i + k < 12)
				{
					if (map[i + k][j] != '.')
						break;
				}
				else
					break;
			}
			map[i + k - 1][j] = map[i][j];
			if(k - 1 != 0)
				map[i][j] = '.';
		}	
}
int dfs()
{
	int ret = 0;
	while (1)
	{
		entire_flag = 0;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				cur_v_size = v.size();
				
				if (map[i][j] != '.')
					calc(i, j, map[i][j]);
				
				change_v_size = v.size();
				//cout << change_v_size << " ";
				if (change_v_size - cur_v_size >= 4)
				{
					for (int i = 0; i < v.size(); i++)
						map[v[i].first][v[i].second] = '.';
					entire_flag = 1;
				}
				v.clear();
				
			}
			//cout << endl;
		}
			
		if (entire_flag == 1)
			ret += 1;
		else
			break ;

		/*cout << endl;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
				cout << map[i][j];
			cout << endl;
		}*/
		
		for (int i = 0; i < 12; i++) //visit 배열 초기화
			for (int j = 0; j < 6; j++)
				visit[i][j] = 0;

		pull_down();
		/*cout << "pull-down후" << endl;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
				cout << map[i][j];
			cout << endl;
		}*/
	}
	return ret;
}
int main()
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> map[i][j];

	cout << dfs() << endl;
		
	return 0;
}