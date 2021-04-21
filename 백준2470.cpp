#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> v;
pair<int, int> answer;
int min_ans = 2000000001;
void input()
{
	cin >> N; 
	for (int i = 0; i < N; i++)
	{
		int a; cin >> a;
		v.push_back(a);
	}
}
void solve()
{
	int start = 0, end = N - 1;
	while (start < end)
	{
		int sum = v[start] + v[end];
		if (abs(sum) < min_ans)
		{
			answer = { v[start], v[end] };
			min_ans = abs(sum);
		}

		if (sum < 0) start++;
		else end--;
	}
}
int main()
{
	input();
	sort(v.begin(), v.end());
	solve();
	cout << answer.first << " " << answer.second << endl;
	return 0;
}