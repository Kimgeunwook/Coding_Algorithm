#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321;
int arr[51][51];
int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			arr[i][j] = INF;

	for (int i = 0; i < road.size(); i++)
	{
		int start = road[i][0];
		int dest = road[i][1];
		int weight = road[i][2];
		arr[start][dest] = min(arr[start][dest], weight);
		arr[dest][start] = min(arr[dest][start], weight);
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

	for (int i = 2; i <= N; i++)
		if (arr[1][i] <= K) answer++;
	return answer + 1;
}