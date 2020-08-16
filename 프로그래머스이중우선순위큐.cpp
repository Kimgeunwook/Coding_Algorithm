//1315시작
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct info {
	int idx, val;
};
struct comp { //내림차순
	bool operator()(info a, info b)
	{
		return a.val < b.val; 
	}
};
struct comp2 { //오름차순
	bool operator()(info a, info b)
	{
		return a.val > b.val;
	}
};
priority_queue<info, vector<info>, comp> pq; //max heap
priority_queue<info, vector<info>, comp2> pq2; //min heap
bool visit[1000001];
vector<int> solution(vector<string> operations) {
	vector<int> answer;
	for (int i = 0; i < operations.size(); i++)
	{
		if (operations[i][0] == 'I') //넣는 것
		{
			if (operations[i][2] == '-')
			{
				int temp = -1 * stoi(operations[i].substr(3, operations[i].size()));
				info newbie = { i , temp };
				pq.push(newbie);
				pq2.push(newbie);
			}
			else
			{
				int temp = stoi(operations[i].substr(2, operations[i].size()));
				info newbie = { i , temp };
				pq.push(newbie);
				pq2.push(newbie);
			}
		}
		else
		{
			if (operations[i][2] == '-') //최소값 빼는것
			{
				while (!pq2.empty())
				{
					info cur = pq2.top();
					if (visit[cur.idx])
					{
						pq2.pop();
					}
					else
					{
						visit[cur.idx] = true;
						pq2.pop();
						break;
					}
				}
			}
			else //최대값 빼는것
			{
				while (!pq.empty())
				{
					info cur = pq.top();
					if (visit[cur.idx])
					{
						pq.pop();
					}
					else
					{
						visit[cur.idx] = true;
						pq.pop();
						break;
					}
				}
			}
		}
	}

	while (!pq.empty())
	{
		info cur = pq.top();
		if (!visit[cur.idx])
		{
			answer.push_back(cur.val);
			break;
		}
		pq.pop();
	}
	while (!pq2.empty())
	{
		info cur = pq2.top();
		if (!visit[cur.idx])
		{
			answer.push_back(cur.val);
			break;
		}
		pq2.pop();
	}
	if (answer.size() == 2) {
		cout << answer[0] << " " << answer[1] << endl;
		return answer;
	}
	else
	{
		answer.push_back(0);
		answer.push_back(0);
		cout << answer[0] << " " << answer[1] << endl;
		return answer;
	}
	
}
int main()
{
	solution({ "I 7","I 5","I -5","D -1" });
	return 0;
}