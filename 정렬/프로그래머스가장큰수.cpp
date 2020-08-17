#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(string a, string b) {
    return a + b > b + a;
}
vector<string> v;
string solution(vector<int> numbers) {
    string answer = "";
    
    for (int i = 0; i < numbers.size(); i++)
        v.push_back(to_string(numbers[i]));
    sort(v.begin(), v.end(), cmp);
    if (v[0] == "0") return "0";
    for (int i = 0; i < v.size(); i++)
        answer += v[i];
    return answer;
}
int main()
{


    solution({ 3, 30, 34, 5, 9 });
    
    return 0;
}
