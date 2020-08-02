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
//k번째수는 최대 k이다 .
//고로 1~k까지 나올 수 있으므로 1,k를 끝점으로 이분탐색 고고
//만약 이분탐색점(=mid)보다 이하인 점들이 k보다 작으면 최소한 k번쨰수가 mid보단 큰거다
//만약2 이분탐색점(=mid)보다 이하인 점이 k 이상이면 k번쨰수가 mid일 확률이 있는거니 answer를 mid로 체크하고 _emd = mid - 1로 체크하고 진행