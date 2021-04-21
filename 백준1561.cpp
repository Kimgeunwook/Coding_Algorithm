#include <iostream>
using namespace std;
long long N, M;
int arr_m[10001];
long long start, _end;
void input()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
		cin >> arr_m[i];
}
long long calc(long long n)
{
	if (n == 0) return M;
	long long ret = 0;
	for (long long i = 1; i <= M; i++)
		ret += (n / arr_m[i]);

	return ret + M;
}
void solve()
{
	start = 1, _end = N * 30;
	while (start < _end)
	{
		long long mid = (start + _end) / 2;
		if (calc(mid) < N) start = mid + 1;
		else _end = mid;
	}
}
void get_answer()
{
	long long cnt = N - calc(_end - 1);
	int i = 1;
	for (; i <= M; i++)
	{
		if (_end % arr_m[i] == 0) cnt--;
		
		if (!cnt) break;
	}
	cout << i << endl;
}
int main()
{
	input();
	/*if (N <= M) 
		cout << N << endl;
	else
	{*/
		solve();
		get_answer();
	//}
		
	return 0;
}