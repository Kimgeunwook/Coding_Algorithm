#include <iostream>
#include <stdio.h>
#include <queue>
#include <functional>
using namespace std;
bool map[26][26];
bool visit[26][26];
int _count = 0;
priority_queue<int, vector<int>, greater<int>> v;

void search(int x, int y)
{
	visit[x][y] = 1;
	_count++;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if ((i*j == 0) && !(i == 0 && j == 0))
				if (map[x + i][y + j] == 1 && visit[x + i][y + j] == 0)
					search(x + i, y + j);

}
int main()
{
	int num;
	int total = 0;
	cin >> num;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			scanf("%1d", &map[i][j]);

	for (int i = num; i >= 1; i--)
		for (int j = num; j >= 1; j--)
		{
			if (visit[i][j] == 0 && map[i][j] == 1)
			{
				search(i, j);
				total++;
				v.push(_count);
				_count = 0;
			}
		}
	cout << total << endl;
	while (!v.empty())
	{
		cout << v.top() << endl;
		v.pop();
	}

	return 0;
}