//13:26Ω√¿€
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> m;
map<string, int>::iterator it;
vector<int> v;
int temp[30];
int answer = 1;

int solution(vector<vector<string>> clothes) {
    for (int i = 0; i < clothes.size(); i++)
        m[clothes[i][1]] ++;
    
    for (it = m.begin(); it != m.end(); it++)
        v.push_back(it->second);
 
    for (int i = 0; i < v.size(); i++)
        answer *= v[i] + 1;
    return answer - 1 ;
    /*if (m.size() == 1) return answer;
    else return answer -1;*/
}
int main()
{
    solution({{"yellow_hat", "headgear"}, { "blue_sunglasses","eyewear" }, { "green_turban", "headgear"}});
    return 0;
}