#include <iostream>
#include <queue>
#include <deque>
using namespace std;
int N, applenum, dirnum;
int map[101][101];
int visit[101][101];
int snake_dir = 1;
queue<pair<int, char>> q;
deque<pair<int, int>> dq;
int play()
{
	int k = 0;
	while(1)
	{
		int curx = dq.front().first;
		int cury = dq.front().second;
		
		if (snake_dir == 0)//북
		{
			if (visit[curx - 1][cury] == 1 || curx - 1 < 1)
				return k;
			else if (map[curx - 1][cury] == 5) //사과면
			{
				dq.push_front(make_pair(curx - 1, cury));
				map[curx - 1][cury] = 0;
				visit[curx - 1][cury] = 1;
			}
			else if (map[curx - 1][cury] == 0)
			{
				visit[curx - 1][cury] = 1;
				dq.push_front(make_pair(curx - 1, cury));
				visit[dq.back().first][dq.back().second] = 0;
				dq.pop_back();
			}
		}
		else if (snake_dir == 1)//동
		{
			if (visit[curx][cury + 1] == 1 || cury + 1 > N)
				return k;
			else if(map[curx][cury + 1] == 5) //사과면
			{
				dq.push_front(make_pair(curx, cury + 1));
				map[curx][cury + 1] = 0;
				visit[curx][cury + 1] = 1;
			}
			else if (map[curx][cury + 1] == 0)
			{
				visit[curx][cury + 1] = 1;
				dq.push_front(make_pair(curx, cury + 1));
				visit[dq.back().first][dq.back().second] = 0;
				dq.pop_back();
			}
		}
		else if (snake_dir == 2) // 남
		{
			if (visit[curx + 1][cury] == 1 || curx + 1 > N)
				return k;
			else if (map[curx + 1][cury] == 5) //사과면
			{
				visit[curx + 1][cury] = 1;
				dq.push_front(make_pair(curx + 1, cury));
				map[curx + 1][cury] = 0;
			}
			else if (map[curx + 1][cury] == 0)
			{
				visit[curx + 1][cury] = 1;
				dq.push_front(make_pair(curx + 1, cury));
				visit[dq.back().first][dq.back().second] = 0;
				dq.pop_back();
			}
		}
		else if (snake_dir == 3) //서
		{
			
			if (visit[curx][cury - 1] == 1 || cury - 1 < 1)
			{
				return k;
			}	
			else if (map[curx][cury - 1] == 5) //사과면
			{
				dq.push_front(make_pair(curx, cury - 1));
				map[curx][cury - 1] = 0;
				visit[curx][cury - 1] = 1;
			}
			else if (map[curx][cury - 1] == 0)
			{
				visit[curx][cury - 1] = 1;
				dq.push_front(make_pair(curx, cury - 1));
				visit[dq.back().first][dq.back().second] = 0;
				dq.pop_back();
				
			}
		}
		k++;
		if(!q.empty())
			if (q.front().first == k) //방향전환타임
			{
				if (q.front().second == 'D')
					snake_dir = (snake_dir + 1) % 4;
				else
					snake_dir = (snake_dir + 3) % 4;
				q.pop();
			}
		
		
	}
}
int main()
{
	cin >> N;
	cin >> applenum;
	for (int i = 0; i < applenum; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 5;//5는 사과를 의미
	}
	cin >> dirnum;
	for (int i = 0; i < dirnum; i++)
	{
		int x;
		char y;
		cin >> x >> y;
		q.push(make_pair(x, y));
	}
	dq.push_back(make_pair(1, 1));
	visit[1][1] = 1;
	cout<<play() + 1<<endl;
	
	return 0;
}