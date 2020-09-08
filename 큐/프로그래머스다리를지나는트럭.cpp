//1945시작
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct info
{
	int time, weight;
};
queue<info> pq;
queue<int> ready_q;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	for (int i = 0; i < truck_weights.size(); i++) ready_q.push(truck_weights[i]);

	int answer = 0;
	int cur_weight = 0;
	while(1)
	{
		if (pq.empty() && ready_q.empty()) break; //다리에도 없고 레디에도 없으면

		if (pq.empty()) //다리에 아무도 없으면
		{
			info temp = { answer, ready_q.front()};
			pq.push(temp);
			cur_weight += ready_q.front();
<<<<<<< Updated upstream:큐/프로그래머스다리를지나는트럭.cpp
			cout << answer << "에" << temp.weight << "진입" << endl;
=======
>>>>>>> Stashed changes:프로그래머스다리를지나는트럭.cpp
			ready_q.pop();
		}
		else //다리 차 있으면 사이즈검사
		{
			info late = pq.front();
			if (answer - bridge_length == late.time)
			{
				pq.pop();
				cur_weight -= late.weight;
			}
			if (!ready_q.empty())
			{
				int cur = ready_q.front();
				if (cur + cur_weight <= weight) //더 태울수 있으면
				{
					
					info temp = { answer, cur };
					pq.push(temp);
					cur_weight += cur;
<<<<<<< Updated upstream:큐/프로그래머스다리를지나는트럭.cpp
					cout << answer << "에" << temp.weight << "진입" << endl;
=======
>>>>>>> Stashed changes:프로그래머스다리를지나는트럭.cpp
					ready_q.pop();
				}
			}
			
		}
		answer++;
	}
	return answer;
}

int main()
{
	cout << solution(100, 100, {10}) << endl;
	return 0;
}
