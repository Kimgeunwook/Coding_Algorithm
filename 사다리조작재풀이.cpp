#include <iostream>
#include <vector>
struct info
{
	int x, y;
};
using namespace std;
int fmap[31][31];
int map[31][31];
int N, M, H;
int flag = 0;
vector<info> v;
int temp[4];
int answer()
{
	int ret = 0;

	for (int j = 1; j <= N; j++)
	{
		int cur = j;
		for (int i = 1; i <= H; i++)
		{
			if (cur == 1)
			{
				if (fmap[i][cur] == 1)
				{
					cur++;
				}
			}	
			else if (cur == N)
			{
				if (fmap[i][cur - 1] == 1)
				{
					cur--;
				}
			}
			else
			{
				if (fmap[i][cur] == 1)
				{
					cur++;
				}
				else if (fmap[i][cur - 1] == 1)
				{
					cur--;
				}
					
			}
		}
		if (cur != j) //시작점 도착점 다르면
			return -1;
	}
	if (ret == 0) return 1; //다 자기갈길 갔으면
}
void dfs(int ob, int cnt,int idx)
{
	if (cnt == ob)
	{
		for (int a = 1; a <= H; a++)
			for (int b = 1; b < N; b++)
				fmap[a][b] = map[a][b];

		for (int i = 0; i < ob; i++) //가로선긋기
		{
			if (fmap[v[temp[i]].x][v[temp[i]].y] == 1) //이미 해본 조합
			{
				return;
			}
				
			fmap[v[temp[i]].x][v[temp[i]].y] = 1;
		}
		if (answer() == 1)//i가 i나오면
			flag = 1;
	}
	else {
		for (int i = idx; i < v.size(); i++)
		{
			if (flag == 1)
				return;

			temp[cnt] = i;
			dfs(ob, cnt + 1, i + 1);
		}
	}
}
int main()
{
	cin >> N >> M >> H;
	int x, y;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		map[x][y] = 1;
	}

	for(int i =1; i <= H; i++)
		for (int j = 1; j < N; j++)
		{
			if (map[i][j] == 0)
			{
				info a = { i,j };
				v.push_back(a);
			}
		}

	for (int i = 0; i <= 3; i++)
	{
		if (i > v.size())
			break;
		flag = 0;
		dfs(i, 0, 0); // i , 몇개채운지, 몇번째꺼 가져간지
		if (flag == 1)
		{
			cout << i << endl;
			return 0;
		}		
	}

	cout << -1 << endl;
	return 0;
}