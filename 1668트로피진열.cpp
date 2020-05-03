#include <iostream>
using namespace std;
int arr[51];
int main()
{
	int num, max = 0;
	int l_sightmax = 0, r_sightmax = 0;
	int l_sightcount = 0, r_sightcount = 0;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cin >> arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	for (int i = 1; i <= num; i++)
	{
		if (arr[i] == max)
		{
			l_sightcount++;
			break;
		}
		else if (arr[i] > l_sightmax)
		{
			l_sightcount++;
			l_sightmax = arr[i];
		}
	}
	for (int i = num; i >= 1; i--)
	{
		if (arr[i] == max)
		{
			r_sightcount++;
			break;
		}
		else if (arr[i] > r_sightmax)
		{
			r_sightcount++;
			r_sightmax = arr[i];
		}
	}
	cout << l_sightcount << endl;
	cout << r_sightcount << endl;
	return 0;
}