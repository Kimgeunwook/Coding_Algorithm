#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <time.h>
using namespace std;
int N, M, K;
int map[10][10], vitamin[10][10]; // �ָ�   �Է¾�и�
vector<pair<int, int>> five;

struct tree
{
	int x;
	int y;
	int age;
};
struct compare {
	bool operator()(tree a, tree b)
	{
		return a.age > b.age;
	}
};

priority_queue<tree, vector<tree>, compare> pqtree;
priority_queue<tree, vector<tree>, compare> temp;
int visit[10][10];
void spring_summer()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = 0;
	five.clear();
	while (!pqtree.empty())
	{
		int cur_x = pqtree.top().x;
		int cur_y = pqtree.top().y;
		int cur_age = pqtree.top().age;
		if (cur_age <= map[cur_x][cur_y] && visit[cur_x][cur_y] == 0) // ��� ������������
		{
			map[cur_x][cur_y] -= cur_age;
			cur_age += 1;
			if (cur_age % 5 == 0)
				five.push_back(make_pair(cur_x,cur_y));
			tree next = { cur_x,cur_y,cur_age };
			temp.push(next);
		}
		else // ��� ��������
		{
			visit[cur_x][cur_y] = 1;
			map[cur_x][cur_y] += (cur_age / 2);
		}
		pqtree.pop();
	}
	pqtree = temp;
	while (!temp.empty())
		temp.pop();
}
void fall()
{
	int size = five.size();
	for (int i = 0; i < size; i++)
	{
		int cur_x = five[i].first;
		int cur_y = five[i].second;
		for(int a = -1; a < 2; a++)
			for(int b = -1; b < 2; b++)
				if (!(a == 0 && b == 0) && cur_x + a >= 0 && cur_x + a < N && cur_y + b >= 0 && cur_y + b < N)
				{
					tree add = {cur_x + a, cur_y + b,1};
					pqtree.push(add);
				}
	}
}
void winter()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] += vitamin[i][j];
}
int main()
{
	time_t start, end;
	double result; 
	start = time(NULL);
	cin >> N >> M >> K; //��ũ��   ��������   �����������

	for (int i = 0; i < N; i++) //ó�� ���� ���5�� �ʱ�ȭ
		for (int j = 0; j < N; j++)
			map[i][j] = 5;

	for (int i = 0; i < N; i++) //�ܿ���
		for (int j = 0; j < N; j++)
			cin >> vitamin[i][j];

	for (int i = 0; i < M; i++)//////////////���� ��ġ �Է¹ޱ�
	{
		int x, y, age;
		cin >> x >> y >> age;
		tree a = { x - 1,y - 1,age };
		pqtree.push(a);
	}

	

	for (int i = 0; i < K; i++)////////K���ݺ�
	{
		spring_summer();
		fall();
		winter();
	}
	cout << pqtree.size() << endl;
	end = time(NULL);
	cout << double(end - start) << endl;
	return 0;
}