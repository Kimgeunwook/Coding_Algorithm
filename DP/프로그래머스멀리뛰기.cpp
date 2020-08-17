#include <string>
#include <vector>
#include <iostream>
using namespace std;
long long dp[2001];
long long solution(int n) {
    
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }
    return dp[n];
}
int main()
{
    solution(4);
    return 0;
}
