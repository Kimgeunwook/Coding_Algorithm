//2130Ω√¿€
#include <iostream>
#include <queue>
using namespace std;
int answer, N;
struct info
{
	int finish, start;
};
struct comp {
	bool operator()(info a, info b)
	{
		if (a.finish != b.finish)
			return a.finish > b.finish;
		else
			return a.start > b.start;
	}
};
priority_queue<info, vector<info>, comp > pq;



void input()
{
	cin >> N;
	while (N--)
	{
		int a, b; cin >> a >> b;
		info newbie = {b, a};
		pq.push(newbie);
	}
}

void solve()
{
	int cur_time = 0;
	while (!pq.empty())
	{
		info cur = pq.top();
		pq.pop();

		if (cur.start >= cur_time)
		{
			answer++;
			cur_time = cur.finish;
		}
	}
}

int main()
{
	input();
	solve();
	cout << answer << endl;
	return 0;
}