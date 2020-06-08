#include <iostream>
using namespace std;
#include <vector>
struct info {
	int x, y, dir, num, location; // 좌표 , 방향, 원본몇번째인지 , 맵에서 몇번째위치인지
};
vector<info> v_original; // 순서유지배열
vector<info> v_map[13][13]; //각 칸에 몇개 쌓인지
vector<info> temp;
int map[13][13], N, K;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int dir_reverse[5] = {0, 2, 1, 4, 3 };
int simulation()
{
	int flag = 0;
	for (int i = 0; i < v_original.size(); i++)
	{
		
		/*for (int  k= 0; k < v_original.size(); k++)
		{
			cout << v_original[k].num << ":" << v_original[k].x << "," << v_original[k].y << "," << v_original[k].dir<<"," <<v_original[k].location << endl;
		}*/
		//cout << i << endl;
		info cur = v_original[i];
		
		if (cur.x + dx[cur.dir] >= 1 && cur.x + dx[cur.dir] <= N && cur.y + dy[cur.dir] >= 1 && cur.y + dy[cur.dir] <= N)
		{
			if (map[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]] == 0)//흰
			{
				//cout << "흰" << endl;
				temp.clear();
				for (int j = 0; j < cur.location; j++)
					temp.push_back(v_map[cur.x][cur.y][j]);

				int SIZE = v_map[cur.x][cur.y].size();
				for (int j = cur.location; j < SIZE; j++)
				{
					int a = v_map[cur.x][cur.y][j].num;
					info newbie = { cur.x + dx[cur.dir] , cur.y + dy[cur.dir] , v_original[a].dir , a ,v_map[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]].size()};
					v_original[a].location = v_map[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]].size();
					v_original[a].x = cur.x + dx[cur.dir];
					v_original[a].y = cur.y + dy[cur.dir];
					v_map[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]].push_back(newbie);
					
					if (v_original[a].location >= 3)
					{
						return -1;
					}
				}
				v_map[cur.x][cur.y] = temp;
				flag = 0;
			}

			else if (map[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]] == 1) // 빨
			{
				//cout << "빨" << endl;
				temp.clear();
				for (int j = 0; j < cur.location; j++)
					temp.push_back(v_map[cur.x][cur.y][j]);

				int SIZE = v_map[cur.x][cur.y].size();

				for (int j = SIZE - 1; j >= cur.location; j--)
				{
					int a = v_map[cur.x][cur.y][j].num;
					info newbie = { cur.x + dx[cur.dir] , cur.y + dy[cur.dir] , cur.dir,a ,v_map[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]].size() };
					v_original[a].x = cur.x + dx[cur.dir];
					v_original[a].y = cur.y + dy[cur.dir];
					v_original[a].location = v_map[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]].size();
					v_map[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]].push_back(newbie);
					if (v_original[a].location >= 3)
					{
						return -1;
					}
				}

				v_map[cur.x][cur.y] = temp;
				flag = 0;
			}

			else if (map[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]] == 2) //파
			{
				//cout << "파" << endl;
				if (flag == 1) // 반대쪽도 파란색이면
				{
					flag = 0;
					continue;
				}
				//flag = 1해주는부분
				v_original[cur.num].dir = dir_reverse[cur.dir];
				flag = 1;
				i--;
			}
		}
		else // 범위 벗어나면
		{
			//cout <<"범위벗어남" << endl;
			if (flag == 1) // 반대쪽도 파란색이면
			{
				flag = 0;
				continue;
			}
			//flag = 1
			v_original[cur.num].dir = dir_reverse[cur.dir];
			flag = 1;
			i--;
		}
	}
	/*for (int k = 0; k < v_original.size(); k++)
	{
		cout << v_original[k].num << ":" << v_original[k].x << "," << v_original[k].y << "," << v_original[k].dir << "," << v_original[k].location << endl;
	}*/
	return 0;
}
int main()
{
	
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];
	int a, b, c;
	for (int i = 0; i < K; i++)
	{
		cin >> a >> b >> c;
		info temp = {a, b, c, i, 0};
		v_original.push_back(temp);
		v_map[a][b].push_back(temp);
	}
	int ret ,T = 0;
	while (T < 1000)
	{
		
		ret = simulation();
		T++;
		if (ret == -1)
		{
			cout << T << endl;
			return 0;
		}
		
	}
	cout << -1 << endl;

	return 0;
}
