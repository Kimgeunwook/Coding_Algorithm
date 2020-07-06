#include <iostream>
#include <string>
using namespace std;
#include <vector>
using namespace std;

int visit[100]; // 이미 나온애들 추가
int solution(vector<int> priorities, int location) {
    int answer = 0;
    while (!visit[location])
    {
        for (int i = 0; i < priorities.size(); i++)
        {
            if (visit[i] == 1) continue;
            int flag = 0;
            for (int j = 0; j < priorities.size(); j++)
            {
                if (visit[j] == 1) continue;
                if (priorities[j] > priorities[i])
                {

                    flag = 1;
                    break; //뒤에 자기보다 큰 숫자가 나오면
                }
                //visit체크되는애가 location이면 나오기
            }
            if (flag == 0)
            {
                visit[i] = 1;
                answer++;
                if (i == location)
                    break;
            }
        }
    }
    
   
    cout << answer;
    return answer;
}
int main()
{
    solution({1, 1, 9, 1, 1, 1}, 0);
    return 0;
}