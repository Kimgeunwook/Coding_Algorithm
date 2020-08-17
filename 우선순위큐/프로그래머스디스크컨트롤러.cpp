#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct info {
    int a,  b;
};

bool comp(vector<int> x, vector<int> y)
{
    if (x[0] != y[0]) //들어온 시간순 소팅 시간같으면 끝나는 시간 짧은게 먼저
        return x[0] < y[0];
    else
        return x[1] < y[1];
}

struct comp2 { //일 할 후보들
    bool operator()(info x, info y)
    {
        return x.b > y.b;
    }
};
priority_queue<info, vector<info>, comp2> pq_ready; //현재 시간내에 들어와서 실행할 수 있는 작업

int solution(vector<vector<int>> jobs) {
    int answer = 0, cur_time = 0, idx = 0; // 정답, 현재 시간, 현재 끝나기로 예약되어있는 시간     
    int left_jobs = jobs.size(); //남은 일수
   
    sort(jobs.begin(), jobs.end(), comp);
    while (left_jobs > 0)
    {
        //pq에서 pq_ready로 넘어갈수 있는애들 다 넘기기
        while ((idx < jobs.size()) && jobs[idx][0] <= cur_time)
        {
            info newbie = { jobs[idx][0] , jobs[idx][1] };
            pq_ready.push(newbie);
            idx++;
        }
        if (!pq_ready.empty()) {
            info temp = pq_ready.top();
            answer += cur_time - temp.a + temp.b;
            cur_time += temp.b;
            left_jobs--;
            pq_ready.pop();
        }
        else //pq_ready에서 실행할 애 없으면 시간만 ++
        {
            cur_time++;
        }
    }
    
    return answer / jobs.size();
}
int main()
{
    solution( { {0, 3} , { 1, 9 }, { 2, 6 } });
    return 0;
}
