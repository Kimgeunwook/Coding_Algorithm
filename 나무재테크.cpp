#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
int N, M, K;
int map[10][10], vitamin[10][10]; // �ָ�   �Է¾�и�
vector<pair<int, int>> five;
priority_queue<int, vector<int>, greater<int>> pq_tree[10][10];
void spring_summer()
{
	five.clear();
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int sum = 0;
			priority_queue<int, vector<int>, greater<int>> temp[10][10];
			int size = pq_tree[i][j].size();
			
			int original = map[i][j];
			for (int k = 0; k < size; k++)
			{
	
				if (sum + pq_tree[i][j].top() <= original)//��� ������ ������
				{
					sum += pq_tree[i][j].top();
					map[i][j] -= pq_tree[i][j].top();
					temp[i][j].push(pq_tree[i][j].top() + 1);
					if ((pq_tree[i][j].top() + 1) % 5 == 0)
					{
						five.push_back(make_pair(i, j));
					}
					pq_tree[i][j].pop();
				}
				else
				{
					if (pq_tree[i][j].size() != 0)
					{
						map[i][j] += pq_tree[i][j].top() / 2;
						pq_tree[i][j].pop();
					}
				}
				
			}
			pq_tree[i][j] = temp[i][j];
		}

	
}
void fall()
{
	for (int i = 0; i < five.size(); i++)
	{	
		int cur_x = five[i].first;
		int cur_y = five[i].second;
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
			{
				if (!(i == 0 && j == 0))
					if (cur_x + i >= 0 && cur_x + i < N && cur_y + j >= 0 && cur_y + j < N)
						pq_tree[cur_x + i][cur_y + j].push(1);
			}	
	}
}
void winter()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] += vitamin[i][j];
}
int answer()
{
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ret += pq_tree[i][j].size();
	return ret;
}
int main()
{
	cin >> N >> M >> K; //��ũ��   ��������   �����������

	for (int i = 0; i < N; i++) //ó�� ���� ���5�� �ʱ�ȭ
		for (int j = 0; j < N; j++)
			map[i][j] = 5;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> vitamin[i][j];

	for (int i = 0; i < M; i++)//////////////���� ��ġ �Է¹ޱ�
	{
		int x, y, age;
		cin >> x >> y >> age;
		pq_tree[x - 1][y - 1].push(age);
	}
		
	for (int i = 0; i < K; i++)////////K���ݺ�
	{
		spring_summer();
		fall();
		winter();
	}
	cout << answer() << endl;
	return 0;
}