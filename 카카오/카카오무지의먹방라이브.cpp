#include <iostream>
#include <string>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
struct info {
	int num, idx;
};
struct comp {
	bool operator()(info a, info b)
	{
		if (a.num != b.num)
			return a.num > b.num;
		else
			return a.idx > b.idx;
	}
};
priority_queue<info, vector<info>, comp> pq;
bool visit[200000];
int solution(vector<int> food_times, long long k) {
	int answer = 0;

	for (int i = 0; i<food_times.size(); i++)
	{
		info newbie = { food_times[i],i };
		pq.push(newbie);
	}

	long long turn = 0;
	int length = food_times.size();

	while (!pq.empty())
	{
		info cur = pq.top();
		if (cur.num <= turn) // 나갈수 있는애면 나가고 continue
		{
			visit[cur.idx] = true;
			length -= 1;
			pq.pop();
			continue;
		}
		//남은시간 고려해서 나갈수 있으면 turn, k , length 조절하고 나가기
		if ((cur.num - turn) * length <= k)
		{
			visit[cur.idx] = true;
			k -= (cur.num - turn) * length;
			length -= 1;
			turn += cur.num - turn;
			pq.pop();
		}
		else
		{
			break;
		}
	}
	if (length == 0) return -1;
	long long cnt = k % length + 1;
	for (int i = 0; i < food_times.size(); i++)
	{
		if (!visit[i]) {
			cnt--;
			if (cnt == 0) answer = i;
		}

	}
	return answer + 1;
}