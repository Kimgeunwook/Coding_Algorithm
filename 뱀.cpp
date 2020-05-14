#include <iostream>
#include <queue>
#include <list>
using namespace std;
int map[102][102];
queue<pair<int, char>> q;
int  snake_dir = 2; //1북 2동 3남 4서
list<pair<int, int>> snake_body;
auto it = snake_body.begin();

int search()
{
	for (int i = 1; ; i++) 
	{
		
		if (snake_dir == 1)
		{
			for (it = snake_body.begin(); it != snake_body.end() ; it++) //자기자신 몸
			{
				if (snake_body.front().first - 1 == it->first && snake_body.front().second == it->second)//@@@@@@@@@@검사
					return i;
			}
			if (map[snake_body.front().first - 1][snake_body.front().second] == 0) //벽
				return i;
			else if (map[snake_body.front().first - 1][snake_body.front().second] == 2) //사과
			{
				map[snake_body.front().first - 1][snake_body.front().second] = 1;
				snake_body.push_front(make_pair(snake_body.front().first - 1, snake_body.front().second));
			}
			else //빈공간
			{
				snake_body.push_front(make_pair(snake_body.front().first - 1, snake_body.front().second));
				snake_body.pop_back(); //길이 줄여주기
			}
		}
		else if (snake_dir == 2)
		{
			for (it = snake_body.begin(); it != snake_body.end(); it++) //자기자신 몸
			{
				if (snake_body.front().first  == it->first && snake_body.front().second + 1 == it->second)//@@@@@@@@@@검사
					return i;
			}
			if (map[snake_body.front().first][snake_body.front().second + 1] == 0) //벽
				return i;
			else if (map[snake_body.front().first][snake_body.front().second + 1] == 2) //사과
			{
				map[snake_body.front().first][snake_body.front().second + 1] = 1;
				snake_body.push_front(make_pair(snake_body.front().first, snake_body.front().second + 1));
			}
			else //빈공간
			{
				snake_body.push_front(make_pair(snake_body.front().first, snake_body.front().second + 1));
				snake_body.pop_back(); //길이 줄여주기
			}
		}
		else if (snake_dir == 3)
		{
			for (it = snake_body.begin(); it != snake_body.end(); it++) //자기자신 몸
			{
				if (snake_body.front().first + 1 == it->first && snake_body.front().second == it->second)//@@@@@@@@@@검사
					return i;
			}
			if (map[snake_body.front().first + 1][snake_body.front().second] == 0) //벽
				return i;
			else if (map[snake_body.front().first + 1][snake_body.front().second] == 2) //사과
			{
				map[snake_body.front().first + 1][snake_body.front().second] = 1;
				snake_body.push_front(make_pair(snake_body.front().first + 1, snake_body.front().second));
			}
			else //빈공간
			{
				snake_body.push_front(make_pair(snake_body.front().first + 1, snake_body.front().second));
				snake_body.pop_back(); //길이 줄여주기
			}
		}
		else
		{
			for (it = snake_body.begin(); it != snake_body.end(); it++) //자기자신 몸
			{
				if (snake_body.front().first == it->first && snake_body.front().second - 1 == it->second)//@@@@@@@@@@검사
					return i;
			}
			if (map[snake_body.front().first][snake_body.front().second - 1] == 0) //벽
				return i;
			else if (map[snake_body.front().first][snake_body.front().second - 1] == 2) //사과
			{
				map[snake_body.front().first][snake_body.front().second - 1] = 1;
				snake_body.push_front(make_pair(snake_body.front().first, snake_body.front().second - 1));
			}
			else //빈공간
			{
				snake_body.push_front(make_pair(snake_body.front().first, snake_body.front().second - 1));
				snake_body.pop_back(); //길이 줄여주기
			}
		}
		if (!q.empty())
			if (i == q.front().first) //뱀 방향 바꾸기
			{
				if (q.front().second == 'D')
				{
					if (snake_dir != 4)
						snake_dir += 1;
					else
						snake_dir = 1;
				}
				else
				{
					if (snake_dir != 1)
						snake_dir -= 1;
					else
						snake_dir = 4;
				}
				q.pop();
			}
	} 
	
}
int main()
{
	
	int N, K, L;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			map[i][j] = 1; //1은 빈칸을 의미 0은 벽
	
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int apple_x, apple_y;
		cin >> apple_x >> apple_y;
		map[apple_x][apple_y] = 2; // 2는 사과를 의미
	}

	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int dir_int;
		char dir_char;
		cin >> dir_int >> dir_char;
		q.push(make_pair(dir_int, dir_char));
	}
	snake_body.push_front(make_pair(1, 1));
	int answer = search();
	cout<< answer<< endl;
	
	return 0;
}