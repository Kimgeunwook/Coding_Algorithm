<<<<<<< Updated upstream:우선순위큐/프로그래머스야근지수.cpp
//1446½ÃÀÛ
=======
//1446���� 1502��
>>>>>>> Stashed changes:프로그래머스야근지수.cpp
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <functional>
#include <queue>
priority_queue<int, vector<int>> pq;
long long solution(int n, vector<int> works) {
	long long answer = 0;
	for (int i = 0; i < works.size(); i++) pq.push(works[i]);

	while (n--)
	{
		int cur = pq.top();
		pq.pop();
		pq.push(--cur);
	}

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();
		if (cur > 0) answer += cur * cur;
	}
	return answer;
}

int main()
{
	cout << solution(3,{ 1, 1 }) << endl;
	return 0;
}
