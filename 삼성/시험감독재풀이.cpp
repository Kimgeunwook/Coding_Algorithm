#include <iostream>
using namespace std;
int N, B, C;
int arr[1000001];
long long sum = 0;
int main()
{
	cin >> N;
	sum = N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> B >> C;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] - B > 0)
		{
			if ((arr[i] - B) % C == 0)
			{
				sum += (arr[i] - B) / C;
			}
			else
			{
				sum += (arr[i] - B) / C + 1;
			}
		}
	}
		

	cout << sum << endl;
	return 0;
}
