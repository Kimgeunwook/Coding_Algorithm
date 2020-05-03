#include <iostream>
#include <stdio.h>
using namespace std;
#include <queue>
class point
{
public:
	int x;
	int y;
	int weight; //그자리까지 갈때의 count값
	point(int _x, int _y, int _weight)
	{
		x = _x;
		y = _y;
		weight = _weight;
	}
};
queue<point> q;
bool map[101][101];
bool is_visit[101][101];//방문한곳 표시
int N, M;
int _count, flag = 0;
void visit(int x, int y, int count)
{

	for (int i = 1; i>-2; i--)
		for (int j = 1; j>-2; j--)
			if ((i*j == 0) && !(i == 0 && j == 0)) //4방향 체크
				if (map[x + i][y + j] == 1 && is_visit[x + i][y + j] == 0) //1인곳&&방문안한곳
				{
					if (x + i == N && y + j == M) //도착점이면
					{
						flag = 1;   //flag=1설정
						_count = count + 1;
						return;
					}
					else
					{
						q.push(point(x + i, y + j, count + 1)); //도착점 아니면 queue에 추가
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