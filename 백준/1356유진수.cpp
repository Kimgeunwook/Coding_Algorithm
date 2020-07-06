#include <iostream>
using namespace std;
int dp[11];
int _size = 1, a = 1;
bool search(int x)
{
	int left = 1, right = 1;
	for (int i = 1; i < x; i++)
		left *= dp[i];
	for (int i = x; i <= _size; i++)
		right *= dp[i];
	if (left == right)
		return true;
	else
		return false;
}
int main()
{
	int num, num_copy;
	cin >> num_copy;
	if (num_copy < 10)
		cout << "NO";
	else
	{
		num = num_copy;
		for (;;)
		{
			if (num_copy / 10 != 0)
			{
				dp[a++] = num_copy % 10;
				num_copy /= 10;
				_size++;
			}
			else
			{
				dp[a] = num_copy;
				break;
			}
		}

		for (int i = 2; i <= _size; i++)
		{
			if (search(i))
			{
				cout << "YES";
				break;
			}
			if (i == _size)
				cout << "NO";
		}
	}

	return 0;
}
