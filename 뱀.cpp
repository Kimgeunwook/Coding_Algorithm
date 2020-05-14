#include <iostream>
#include <queue>
#include <list>
using namespace std;
int map[102][102];
queue<pair<int, char>> q;
int  snake_dir = 2; //1�� 2�� 3�� 4��
list<pair<int, int>> snake_body;
auto it = snake_body.begin();

int search()
{
	for (int i = 1; ; i++) 
	{
		
		if (snake_dir == 1)
		{
			for (it = snake_body.begin(); it != snake_body.end() ; it++) //�ڱ��ڽ� ��
			{
				if (snake_body.front().first - 1 == it->first && snake_body.front().second == it->second)//@@@@@@@@@@�˻�
					return i;
			}
			if (map[snake_body.front().first - 1][snake_body.front().second] == 0) //��
				return i;
			else if (map[snake_body.front().first - 1][snake_body.front().second] == 2) //���
			{
				map[snake_body.front().first - 1][snake_body.front().second] = 1;
				snake_body.push_front(make_pair(snake_body.front().first - 1, snake_body.front().second));
			}
			else //�����
			{
				snake_body.push_front(make_pair(snake_body.front().first - 1, snake_body.front().second));
				snake_body.pop_back(); //���� �ٿ��ֱ�
			}
		}
		else if (snake_dir == 2)
		{
			for (it = snake_body.begin(); it != snake_body.end(); it++) //�ڱ��ڽ� ��
			{
				if (snake_body.front().first  == it->first && snake_body.front().second + 1 == it->second)//@@@@@@@@@@�˻�
					return i;
			}
			if (map[snake_body.front().first][snake_body.front().second + 1] == 0) //��
				return i;
			else if (map[snake_body.front().first][snake_body.front().second + 1] == 2) //���
			{
				map[snake_body.front().first][snake_body.front().second + 1] = 1;
				snake_body.push_front(make_pair(snake_body.front().first, snake_body.front().second + 1));
			}
			else //�����
			{
				snake_body.push_front(make_pair(snake_body.front().first, snake_body.front().second + 1));
				snake_body.pop_back(); //���� �ٿ��ֱ�
			}
		}
		else if (snake_dir == 3)
		{
			for (it = snake_body.begin(); it != snake_body.end(); it++) //�ڱ��ڽ� ��
			{
				if (snake_body.front().first + 1 == it->first && snake_body.front().second == it->second)//@@@@@@@@@@�˻�
					return i;
			}
			if (map[snake_body.front().first + 1][snake_body.front().second] == 0) //��
				return i;
			else if (map[snake_body.front().first + 1][snake_body.front().second] == 2) //���
			{
				map[snake_body.front().first + 1][snake_body.front().second] = 1;
				snake_body.push_front(make_pair(snake_body.front().first + 1, snake_body.front().second));
			}
			else //�����
			{
				snake_body.push_front(make_pair(snake_body.front().first + 1, snake_body.front().second));
				snake_body.pop_back(); //���� �ٿ��ֱ�
			}
		}
		else
		{
			for (it = snake_body.begin(); it != snake_body.end(); it++) //�ڱ��ڽ� ��
			{
				if (snake_body.front().first == it->first && snake_body.front().second - 1 == it->second)//@@@@@@@@@@�˻�
					return i;
			}
			if (map[snake_body.front().first][snake_body.front().second - 1] == 0) //��
				return i;
			else if (map[snake_body.front().first][snake_body.front().second - 1] == 2) //���
			{
				map[snake_body.front().first][snake_body.front().second - 1] = 1;
				snake_body.push_front(make_pair(snake_body.front().first, snake_body.front().second - 1));
			}
			else //�����
			{
				snake_body.push_front(make_pair(snake_body.front().first, snake_body.front().second - 1));
				snake_body.pop_back(); //���� �ٿ��ֱ�
			}
		}
		if (!q.empty())
			if (i == q.front().first) //�� ���� �ٲٱ�
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
			map[i][j] = 1; //1�� ��ĭ�� �ǹ� 0�� ��
	
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int apple_x, apple_y;
		cin >> apple_x >> apple_y;
		map[apple_x][apple_y] = 2; // 2�� ����� �ǹ�
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