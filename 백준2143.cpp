#include <iostream>
using namespace std;
#include <map>
map<long, long> dp_a;
int T;
long long A[1001], B[1001], sum_a[1001], sum_b[1001];
long long  answer = 0;
int SIZE_A, SIZE_B;
void input()
{
	cin >> T;

	cin >> SIZE_A;
	int sum = 0;
	for (int i = 1; i <= SIZE_A; i++)
	{
		cin >> A[i];
		sum += A[i];
		sum_a[i] = sum;
	}

	cin >> SIZE_B;
	for (int i = 1; i <= SIZE_B; i++)
	{
		cin >> B[i];
	}
}
void check_all_case()
{
	
	for (int start = 0; start < SIZE_A; start++)
		for (int end = start + 1; end <= SIZE_A; end++)
		{
			dp_a[sum_a[end] - sum_a[start]]++;
		}
			

	
	for (int start = 0; start <= SIZE_B; start++)
	{
		long long sum = 0;
		for (int end = start + 1; end <= SIZE_B; end++)
		{
			sum += B[end];
			answer += dp_a[T - sum];
		}
	}
		
	
}

int main()
{
	input();
	check_all_case();
	cout << answer << endl;
	return 0;
}