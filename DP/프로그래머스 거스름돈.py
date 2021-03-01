def solution(n, money):
    global dp
    dp = [0 for _ in range(100001)]
    for cur_money in money: # 1.. 2.. 5
        dp[cur_money] = (dp[cur_money] + 1) % 1000000007
        for idx in range(cur_money + 1, n + 1): 
            dp[idx] = dp[idx] % 1000000007 + dp[idx - cur_money] % 1000000007
    return dp[n]

# dp 정 안될거같으면 2차원으로도 생각해야함