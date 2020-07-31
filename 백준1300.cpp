#include <iostream>
#include <algorithm>
using namespace std;
int N, k;
int main()
{
	cin >> N >> k;
	int start = 1, _end = k;
	int answer = 0;
	while (start <= _end)
	{
		int mid = (start + _end) / 2;
		int cnt = 0;
		for (int i = 1; i <= N; i++)
			cnt += min(N, (mid / i));

		cout << mid << " " << cnt << endl;
		if (cnt < k)
		{
			start = mid + 1;
		}
		else
		{
			answer = mid;
			_end = mid - 1;
		}
	}
	cout << answer <<endl;
	return 0;
}