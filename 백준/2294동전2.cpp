#include <iostream>
#include <algorithm>
using namespace std;
////https://jaemin8852.tistory.com/163 참고
int main() {
	int coin_num, object_money, coin[101], dp[10001];//동전 개수, 목표 돈 , 동전배열, 답 배열

	cin >> coin_num >> object_money;

	for (int i = 1; i <= coin_num; i++)
		cin >> coin[i];

	for (int i = 1; i <= object_money; i++)
		dp[i] = 987654321;

	dp[0] = 0;

	for (int i = 1; i <= coin_num; i++)
	{
		for (int j = coin[i]; j <= object_money; j++)
		{
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[object_money] == 987654321)
		cout << -1 << endl;
	else
		cout << dp[object_money] << endl;

	return 0;
}
