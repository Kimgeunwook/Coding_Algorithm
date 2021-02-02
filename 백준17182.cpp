//1. floyd로 min dist구하기
//2. dfs로 모든 경우 다 해보기
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
			//자기 자신으로 가는 것은 거리를 무한대로 설정
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
		//지금까지 더한 거리가 가능성 있고, 방문하지 않은곳이면
		if (dist[start][i] + sum < answer && !visit[i])
		{
			visit[i] = true;
			solve(i, sum + dist[start][i], depth + 1);
			//백트래킹
			visit[i] = false;
		}
	}
}
int main()
{
	input();
	floyd();
	//처음에는 방문 표시
	visit[starting_point] = true;
	solve(starting_point, 0, 1);
	cout << answer << endl;
	return 0;
}