dic = {0 : 1}
def solve(n):
    if n in dic:
        return dic[n]

    dic[n] = solve(n // P) + solve(n // Q)
    return dic[n]
N, P, Q = map(int,input().split())
ans = solve(N)
print(ans)