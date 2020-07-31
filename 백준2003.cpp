#include <iostream>
using namespace std;
int N, M, s = 0, e = 0,sum,answer = 0;
int arr[10000];
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	while (1)
	{
		if (sum >= M) sum -= arr[s++];
		else if (e == N) break;
		else sum += arr[e++];
		if (sum == M) answer++;
	}
	cout << answer << endl;
	return 0;
}
