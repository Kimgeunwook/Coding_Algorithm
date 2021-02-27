//2042
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <queue>
struct info {
	int idx, val;
};
struct comp {
	bool operator()(info a, info b)
	{
		if (a.val != b.val)
		{
			return a.val < b.val;
		}
		return a.idx > b.idx;
	}
};
priority_queue<info, vector<info>, comp> pq;
int cur_idx = -1;
string solution(string number, int k) {
	string answer = "";
	for (int i = 0; i <= k; i++)
	{
		info temp = { i, number[i] - '0' };
		pq.push(temp);
	}
	while (!pq.empty())
	{
		info cur = pq.top();
		pq.pop();
		if (cur.idx <= cur_idx) continue;
		answer += to_string( cur.val );
		cur_idx = cur.idx;
		if (k == number.size() - 1) break;
		if (k < number.size() - 1)
		{
			k++;
			info temp = { k, number[k] - '0' };
			pq.push(temp);
		}
		
		
	}

	return answer;
}
int main()
{
	cout << solution("98742", 2) << endl;
	return 0;
}
