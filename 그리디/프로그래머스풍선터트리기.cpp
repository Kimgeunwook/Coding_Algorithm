#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1000001], rdp[1000001];

int solution(vector<int> a) {
	int answer = 2;

	int _min = 1000000000;
	for (int i = 0; i < a.size(); i++)
	{
		_min = min(_min, a[i]);
		dp[i] = _min;
	}
	_min = 1000000000;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		_min = min(_min, a[i]);
		rdp[i] = _min;
	}

	if (a.size() > 1)
		for (int i = 1; i < a.size() - 1; i++)
		{
			if (dp[i - 1] < a[i] && rdp[i + 1] < a[i]) continue;
			answer++;
		}

	if (a.size() == 1) return 1;
	else return answer;
}