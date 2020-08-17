#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int arr[10001];
int solution(vector<int> citations) {
    int answer = -1;
    sort(citations.begin(), citations.end(), greater<int>());
    int len = citations.size();
    for (int i = len; i > 0; i--)
    {
        if (citations[i - 1] >= i) return i;
    }

    cout << answer << endl;
    return answer;
}
int main()
{
    solution({ 1545, 2, 999, 790, 540, 10, 22 });
}
