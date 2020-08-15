//1945����
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
		if (pq.empty() && ready_q.empty()) break; //�ٸ����� ���� ���𿡵� ������

		if (pq.empty()) //�ٸ��� �ƹ��� ������
		{
			info temp = { answer, ready_q.front()};
			pq.push(temp);
			cur_weight += ready_q.front();
			cout << answer << "��" << temp.weight << "����" << endl;
			ready_q.pop();
		}
		else //�ٸ� �� ������ ������˻�
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
				if (cur + cur_weight <= weight) //�� �¿�� ������
				{
					
					info temp = { answer, cur };
					pq.push(temp);
					cur_weight += cur;
					cout << answer << "��" << temp.weight << "����" << endl;
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