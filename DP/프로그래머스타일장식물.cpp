#include <string>
#include <vector>
#include <iostream>
using namespace std;
long long dp[81];
long long solution(int N) {
    long long answer = 0;
    dp[1] = 1;
    if (N >= 2)
    {
        for (int i = 2; i <= N; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[N] << "," << dp[N - 1] << endl;
    cout << dp[N] + dp[N - 1] * 2 + dp[N] * 3 << endl;
    if (N == 1) return 4;
    return dp[N] + dp[N - 1] * 2 + dp[N]  * 3;
}
int main()
{
    solution(5);
    return 0;
}
