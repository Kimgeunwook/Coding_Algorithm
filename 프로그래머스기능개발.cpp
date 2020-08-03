#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include <queue>
queue<int> q;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for (int i = 0; i < progresses.size(); i++)
    {
        for (int j = 1; j < 100; j++)
        {
            if (progresses[i] + j * speeds[i] >= 100)
            {
                q.push(j);
                break;
            }

        }
    }
    int cur = q.front();
    int cnt = 1;
    q.pop();

    if (q.size() == 0) {
        answer.push_back(1);
        return answer;
    }

    while (!q.empty()) {
        if (q.front() <= cur)
        {
            cnt++;
        }
        else {
            answer.push_back(cnt);
            cur = q.front();
            cnt = 1;
        }
        q.pop();
    }
    answer.push_back(cnt);
    return answer;
}