//1541
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool visit[30][30];
int answer = 0;
vector<string> map;
void reset(int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			visit[i][j] = false;
}
void find(int m, int n)
{
	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (map[i][j] != '.' && map[i][j] == map[i][j + 1] && map[i][j] == map[i + 1][j] && map[i][j] == map[i + 1][j + 1])
			{
				visit[i][j] = true;
				visit[i][j + 1] = true;
				visit[i + 1][j] = true;
				visit[i + 1][j + 1] = true;
			}
		}
}
int erase(int m, int n)
{
	int cnt = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j])
			{
				cnt++;
				map[i][j] = '.';
			}
		}
	answer += cnt;
	return cnt;
}
void slide(int m, int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = m - 2; i >= 0; i--)
		{
			int k = 1;
			while (1)
			{
				if (i + k < m)
				{
					if (map[i + k][j] != '.') break;
					k++;
				}
				else break;
			}
			k--;
			if (k != 0)
			{
				map[i + k][j] = map[i][j];
				map[i][j] = '.';
			}
		}
	}
}
int solution(int m, int n, vector<string> board) {
	map = board;
	while (1)
	{
		reset(m, n);
		find(m, n);
		int ret = erase(m, n);
		if (ret == 0) break;
		slide(m, n);
	}
	return answer;
}