#include <iostream>
#include <string>
#include <vector>
using namespace std;
int map[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
	map[1][1] = 1;
	for (int i = 0; i < puddles.size(); i++) map[puddles[i][1]][puddles[i][0]] = -1;
	for(int i = 1; i <= n ;i++)
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == -1 || (i == 1 && j == 1)) continue;

			map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1000000007;
			if (map[i - 1][j] == -1) map[i][j]++;
			if (map[i][j - 1] == -1) map[i][j]++;
		}		
	return map[n][m] % 1000000007;
}
int main()
{
	
	cout << solution(4, 3, { {2 , 2} }) << endl;
	return 0;
}