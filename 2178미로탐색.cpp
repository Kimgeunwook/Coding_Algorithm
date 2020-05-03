#include <iostream>
#include <stdio.h>
using namespace std;
#include <queue>
class point
{
public:
	int x;
	int y;
	int weight; //���ڸ����� ������ count��
	point(int _x, int _y, int _weight)
	{
		x = _x;
		y = _y;
		weight = _weight;
	}
};
queue<point> q;
bool map[101][101];
bool is_visit[101][101];//�湮�Ѱ� ǥ��
int N, M;
int _count, flag = 0;
void visit(int x, int y, int count)
{

	for (int i = 1; i>-2; i--)
		for (int j = 1; j>-2; j--)
			if ((i*j == 0) && !(i == 0 && j == 0)) //4���� üũ
				if (map[x + i][y + j] == 1 && is_visit[x + i][y + j] == 0) //1�ΰ�&&�湮���Ѱ�
				{
					if (x + i == N && y + j == M) //�������̸�
					{
						flag = 1;   //flag=1����
						_count = count + 1;
						return;
					}
					else
					{
						q.push(point(x + i, y + j, count + 1)); //������ �ƴϸ� queue�� �߰�
						is_visit[x + i][y + j] = 1;
					}
				}
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &map[i][j]);

	q.push(point(1, 1, 1));
	is_visit[1][1] = 1;
	while (!q.empty())
	{
		visit(q.front().x, q.front().y, q.front().weight);
		q.pop();
		if (flag == 1)
			break;
	}
	cout << _count << endl;
	return 0;
}