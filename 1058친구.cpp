#include <iostream>
using namespace std;
char map[51][51];
int main()
{
	int num, max_friends = 0;
	cin >> num;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
		{
			cin >> map[i][j];
		}


	for (int i = 1; i <= num; i++)
	{
		int count = 0;
		for (int j = 1; j <= num; j++)
		{
			if (i == j)
				continue;
			if (map[i][j] == 'Y')
			{
				count++;
				continue;
			}
			for (int k = 1; k <= num; k++)
			{
				if ((map[i][k] == 'Y'&&map[k][j] == 'Y'))
				{
					count++;
					break;
				}
			}
		}
		if (count > max_friends)
			max_friends = count;
	}

	cout << max_friends << endl;
	return 0;
}
