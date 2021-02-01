#include <iostream>
using namespace std;
#include <algorithm>
int use_day[16];
int pay[16];
int pay_max[17];
int main()
{
	int num, use_num, payy;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cin >> use_num >> payy;
		use_day[i] = use_num;
		pay[i] = payy;
	}

	pay_max[num + 1] = 0;
	int pay_max_max = 0;
	for (int i = num; i >= 1; i--)
	{
		if (i + use_day[i] - 1 > num)
			pay_max[i] = pay_max_max;
		else
			pay_max[i] = max(pay[i] + pay_max[i + use_day[i]], pay_max[i + 1]);

		if (pay_max_max < pay_max[i])
			pay_max_max = pay_max[i];
	}

	cout << pay_max_max << endl;
	return 0;
}