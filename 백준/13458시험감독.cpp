#include <iostream>
using namespace std;
int dp[1000001];
int main()
{
	int A, B, C;
	long long int cnt = 0;
	cin >> A;

	for (int i = 1; i <= A; i++)
		cin >> dp[i];

	cin >> B >> C;

	for (int i = 1; i <= A; i++)
	{
		dp[i] -= B;
		cnt++;
		if (dp[i] > 0)
		{
			if (dp[i] % C == 0)
			{
				cnt += dp[i] / C;
			}
			else
			{
				cnt += dp[i] / C + 1;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}