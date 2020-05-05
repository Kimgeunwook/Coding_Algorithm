#include <iostream>
using namespace std;
int answer[1001];
int arr[1001];
int main()
{
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> arr[i];
	for (int i = 1; i <= num; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
			if (max < answer[j] && (arr[j]<arr[i]))
				max = answer[j];
		answer[i] = max + 1;
	}
	int real_max = 0;
	for (int i = 1; i <= num; i++)
		if (real_max < answer[i])
			real_max = answer[i];

	cout << real_max;

	return 0;
}