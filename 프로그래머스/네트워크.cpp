#include <iostream>
#include <string>
#include <vector>

using namespace std;
int visit[200];
void dfs(int num, vector<vector<int>> &v)
{
	visit[num] = 1;
	for (int i = 0; i<v[num].size(); i++)
		if (!visit[i] && v[num][i])
			dfs(i, v);
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i<n; i++)
		if (!visit[i])
		{
			answer++;
			dfs(i, computers);
		}
	return answer;
}
