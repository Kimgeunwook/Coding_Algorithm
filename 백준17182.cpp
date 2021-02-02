//1. floyd�� min dist���ϱ�
//2. dfs�� ��� ��� �� �غ���
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
int dist[10][10];
bool visit[10];
int N, starting_point, answer = 987654321;
void input()
{
	cin >> N >> starting_point;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> dist[i][j];
			//�ڱ� �ڽ����� ���� ���� �Ÿ��� ���Ѵ�� ����
			if (i == j) dist[i][j] = INF;
		}
}
void floyd()
{
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		
}
void solve(int start, int sum, int depth)
{
	if (depth == N)
	{
		answer = min(answer, sum);
		
		return;
	}
	for (int i = 0; i < N; i++)
	{
		//���ݱ��� ���� �Ÿ��� ���ɼ� �ְ�, �湮���� �������̸�
		if (dist[start][i] + sum < answer && !visit[i])
		{
			visit[i] = true;
			solve(i, sum + dist[start][i], depth + 1);
			//��Ʈ��ŷ
			visit[i] = false;
		}
	}
}
int main()
{
	input();
	floyd();
	//ó������ �湮 ǥ��
	visit[starting_point] = true;
	solve(starting_point, 0, 1);
	cout << answer << endl;
	return 0;
}