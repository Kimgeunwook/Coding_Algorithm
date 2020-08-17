#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <algorithm>
#include <cmath>
int _visit[10000000];
vector<int> v;
int visit[7];
int temp[7];
int answer = 0;
void dfs(int cnt ,int depth)
{
    if (cnt == depth)
    {
        int num = 0;
        int sub = 1;
        for (int i = depth - 1; i >= 0; i--)
        {
            num += sub * temp[i];
            sub *= 10;
        }
        
        if (num == 0|| num == 1 || _visit[num] == 1) return;
        _visit[num] = 1;

        int flag = 0;
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            //cout << num << endl;
            answer++;
        }
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (visit[i] == 1) continue;
            visit[i] = 1;
            temp[cnt] = v[i];
            dfs(cnt + 1, depth);
            visit[i] = 0;
        }
    }

}
int solution(string numbers) {
    
    for (int i = 0; i < numbers.length(); i++)
    {
        int a = numbers[i] - '0';
        v.push_back(a);
    }
    for (int i = 1; i <= v.size(); i++)
        dfs(0, i);
   
   // cout << answer << endl;
    return answer;
}
int main()
{
    solution("17");
    return 0;
}
