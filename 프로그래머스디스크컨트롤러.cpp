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
    if (x[0] != y[0]) //���� �ð��� ���� �ð������� ������ �ð� ª���� ����
        return x[0] < y[0];
    else
        return x[1] < y[1];
}

struct comp2 { //�� �� �ĺ���
    bool operator()(info x, info y)
    {
        return x.b > y.b;
    }
};
priority_queue<info, vector<info>, comp2> pq_ready; //���� �ð����� ���ͼ� ������ �� �ִ� �۾�

int solution(vector<vector<int>> jobs) {
    int answer = 0, cur_time = 0, idx = 0; // ����, ���� �ð�, ���� ������� ����Ǿ��ִ� �ð�     
    int left_jobs = jobs.size(); //���� �ϼ�
   
    sort(jobs.begin(), jobs.end(), comp);
    while (left_jobs > 0)
    {
        //pq���� pq_ready�� �Ѿ�� �ִ¾ֵ� �� �ѱ��
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
        else //pq_ready���� ������ �� ������ �ð��� ++
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