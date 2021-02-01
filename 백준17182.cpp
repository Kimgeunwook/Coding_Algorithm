#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int arr[10][10];
int dist[10][10];
int N, int starting_point;
int answer = 0;
bool visit[10];
void input()
{
	//초기 거리 무한대로 초기화
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dist[i][j] = INF;

	//출발점 및 각 행간의 거리 입력 받기
	cin >> N >> starting_point;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
}
void floyd()
{
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}

}
void solve(int strt)
{
	int min_idx = INF;
	int min_dist = INF;
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		if (!visit[i] && dist[strt][i] < min_dist)
		{
			flag = true;
			min_idx = i;
			visit[i] = true;
			min_dist = dist[strt][i];
		}
	}
	if (flag)
	{
		answer += min_dist;
		solve(min_idx);
	}
}
int main()
{
	input();
	floyd();
	solve(starting_point);
	cout << answer << endl;
	return 0;
}