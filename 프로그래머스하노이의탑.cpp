#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> answer;
void hanoi(int start, int mid, int finish, int n )
{
    if (n == 1)
    {
        answer.push_back({ start, finish });
        
        return;
    }
    hanoi(start, finish, mid, n - 1);
    answer.push_back({start, finish});
    hanoi(mid, start, finish, n - 1);
    
}
vector<vector<int>> solution(int n) {
    hanoi(1, 2, 3, n);
    return answer;
}
int main()
{
    solution(2);
}