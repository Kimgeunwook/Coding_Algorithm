#include <iostream>
using namespace std;
int N, K;
int dp[1001][1001];
#define modNum 1000000003
void input()
{
	cin >> N;
	cin >> K;
}
void init()
{
	for (int i = 0; i <= N; i++)
	{
		dp[0][i] = 1;
		dp[1][i] = i;
	}
}
void make_dp()
{
	for(int i = 2 ; i <= K; i++)
		for (int j = 2; j <= N; j++)
		{
			// dp[A][B] = B개중 A개 색상을 고르는 경우의 수
			dp[i][j] = (dp[i][j - 1] % modNum + dp[i - 1][j - 2] % modNum) % modNum;
		}
}
int solve() 
{
	return (dp[K][N - 1] % modNum + dp[K - 1][N - 3] % modNum) % modNum;
}
int main()
{
	input();
	init();
	make_dp();
	int answer = solve();
	cout << answer << endl;
	return 0;
}