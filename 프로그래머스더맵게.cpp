#include <iostream>
using namespace std;
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
struct compare {
	bool operator()(int a, int b) //오름차순정렬
	{
		return a > b;
	}
};
priority_queue<int, vector<int>, compare> pq;
int solution(vector<int> scoville, int K) {
	int answer = 0;

	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);

	int flag = 0;
	while (!pq.empty())
	{
		int first = pq.top();
		if (first >= K)
		{
			flag = 1;
			break;
		}
		else {
			if (pq.size() == 0) break;
			pq.pop();
			int second = pq.top();
			if (pq.size() == 0) break;
			pq.pop();
			pq.push(first + second * 2);
		}
		answer++;
	}
	if (flag == 0) return -1;
	return answer;
}
int main()
{
	solution({ 1, 2, 3, 9, 10, 12 }, 7);
	return 0;
}