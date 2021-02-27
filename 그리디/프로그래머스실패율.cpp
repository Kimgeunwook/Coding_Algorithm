//10:06Ω√¿€ 10:35≥°
#include <string>
#include <vector>
#include <queue>
struct info {
	double sucess;
	double tryer;
	int stage;
};
struct comp {
	bool operator()(info a, info b)
	{
		if ((a.tryer - a.sucess) / a.tryer != (b.tryer - b.sucess) / b.tryer)
			return (a.tryer - a.sucess) / a.tryer < (b.tryer - b.sucess) / b.tryer;
		else
			return a.stage > b.stage;
	}
};
using namespace std;
priority_queue<info, vector<info>, comp> pq;
double suc[501];
double tryer[501];
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;


	for (int i = 0; i < stages.size(); i++)
	{
		int limit = stages[i];
		for (int j = 1; j <= limit; j++)
		{
			tryer[j] += 1;
			if (j == limit) break;
			suc[j] += 1;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (tryer[i] == 0)
		{
			tryer[i] = 1;
			suc[i] = 1;
		}
		info newbie = { suc[i], tryer[i], i };
		pq.push(newbie);
	}

	while (!pq.empty())
	{
		answer.push_back(pq.top().stage);
		pq.pop();
	}
	return answer;
}