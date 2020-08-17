#include <iostream>
#include <algorithm>
using namespace std;
int N;
int v[1001];
int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v, v + N);

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (sum + 1 < v[i]) break;
		sum += v[i];
	}
	cout << sum + 1;
	return 0;
}
