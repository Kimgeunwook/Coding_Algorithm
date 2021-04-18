#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int N;
priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int, vector<int>> max_pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		int num; cin >> num;

		if (min_pq.size() == max_pq.size()) max_pq.push(num);
		else min_pq.push(num);

		if (!min_pq.empty() && !max_pq.empty())
			if((min_pq.top() < max_pq.top()))
			{
				int a, b;
				a = max_pq.top();
				b = min_pq.top();
				max_pq.pop();
				min_pq.pop();
				max_pq.push(b);
				min_pq.push(a);
			}

		cout << max_pq.top() << "\n";
	}
	return 0;
}