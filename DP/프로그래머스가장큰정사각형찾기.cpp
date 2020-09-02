//1418Ω√¿€
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int dp[1000][1000];
int solution(vector<vector<int>> board)
{
	int answer = 0;
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j <board[0].size(); j++)
			if (board[i][j] == 1)
			{
				dp[i][j] = 1;

				if (i - 1 >= 0 && j - 1 >= 0)
				{
					int _min = min(dp[i - 1][j], dp[i][j - 1]);

					// for(int k = _min; k >= 1; k--)
					//     if(board[i - k][j - k] == 1)
					//     {
					//         dp[i][j] = k + 1;
					//         break;
					//     }

				}
				answer = max(answer, dp[i][j]);
			}
	return answer * answer;
}