#include <iostream>
using namespace std;
int arr[10001];
int sum[10001];
int N, M;
int main()
{
	cin >> N >> M;
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	for(int i = 0; i <= N ;i++)
		for (int j = 0; j <= N; j++)
		{
			if (sum[j] - sum[i] == M) answer++;
		}
	cout << answer << endl;

	return 0;
}