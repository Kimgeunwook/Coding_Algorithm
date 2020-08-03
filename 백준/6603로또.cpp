#include <iostream>
using namespace std;
int num_array[13];
int dp[7];
int count_point = 1;
void search(int start, int num, int a)
{
	if (a == 1)
	{
		for (int i = start; i <= num; i++)
		{
			dp[6] = num_array[i];
			for (int j = 1; j <= 6; j++)
				cout << dp[j] << " ";
			cout << endl;
		}
	}
	else
	{
		for (int i = start; i <= num - a + 1; i++)
		{
			if (i + a > num + 1)
				continue;
			else
			{
				dp[count_point] = num_array[i];

				if ((a - 1) != 1)
					count_point++;
				search(i + 1, num, a - 1);

				if ((a - 1) == 1)
				{

				}
				else
				{
					count_point--;
				}
			}
		}
	}
}
int main()
{
	int num;
	while (1)
	{
		cin >> num;

		if (num == 0)
			break;

		for (int i = 1; i <= num; i++)
			cin >> num_array[i];

		search(1, num, 6);
		cout << endl;
	}

	return 0;
}