//1410
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int arr[101][101];
#define INF 987654321
int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = INF; //INF = 승부를 명확히 알 수 없는 관계

	for (int i = 0; i < results.size(); i++)
	{
		int winner = results[i][0];
		int loser = results[i][1];
<<<<<<< Updated upstream:플로이드와샬/프로그래머스순위.cpp
		arr[winner][loser] = 1; //1 = 이긴 관계
		arr[loser][winner] = -1; // -1 = 진 관계
=======
		arr[winner][loser] = 1; //1 = �̱� ����
>>>>>>> Stashed changes:프로그래머스순위.cpp
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][k] == 1 && arr[k][j] == 1) arr[i][j] = 1;
			}

	for (int i = 1; i <= n; i++)
	{
		int flag = 0;
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 1 || arr[j][i] == 1) flag++;
		}
		if (flag == n - 1) answer++;
	}

	return answer;
}
int main()
{
	cout << solution(5, { {1, 3},{3, 5},{ 5, 2 },{ 4, 1 } }) << endl;
	return 0;
}
