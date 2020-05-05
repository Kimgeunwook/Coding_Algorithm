#include <iostream>
using namespace std;
#include <algorithm>
int dp_max[3][3];
int dp_min[3][3];
int main()
{
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> dp_max[i % 3][j];
			dp_min[i % 3][j] = dp_max[i % 3][j];
		}


		if (i % 3 == 0)
			for (int j = 0; j < 3; j++)
			{
				if (j == 0)
				{
					dp_min[0][j] = min(dp_min[2][0] + dp_min[0][j], dp_min[2][1] + dp_min[0][j]);
					dp_max[0][j] = max(dp_max[2][0] + dp_max[0][j], dp_max[2][1] + dp_max[0][j]);
				}
				else if (j == 1)
				{
					dp_min[0][j] = min(min(dp_min[2][0] + dp_min[0][j], dp_min[2][1] + dp_min[0][j]), dp_min[2][2] + dp_min[0][j]);
					dp_max[0][j] = max(max(dp_max[2][0] + dp_max[0][j], dp_max[2][1] + dp_max[0][j]), dp_max[2][2] + dp_max[0][j]);
				}
				else
				{
					dp_min[0][j] = min(dp_min[2][2] + dp_min[0][j], dp_min[2][1] + dp_min[0][j]);
					dp_max[0][j] = max(dp_max[2][2] + dp_max[0][j], dp_max[2][1] + dp_max[0][j]);
				}
			}
		else if (i % 3 == 1)
			for (int j = 0; j < 3; j++)
			{
				if (j == 0)
				{
					dp_min[1][j] = min(dp_min[0][0] + dp_min[1][j], dp_min[0][1] + dp_min[1][j]);
					dp_max[1][j] = max(dp_max[0][0] + dp_max[1][j], dp_max[0][1] + dp_max[1][j]);
				}
				else if (j == 1)
				{
					dp_min[1][j] = min(min(dp_min[0][0] + dp_min[1][j], dp_min[0][1] + dp_min[1][j]), dp_min[0][2] + dp_min[1][j]);
					dp_max[1][j] = max(max(dp_max[0][0] + dp_max[1][j], dp_max[0][1] + dp_max[1][j]), dp_max[0][2] + dp_max[1][j]);
				}
				else
				{
					dp_min[1][j] = min(dp_min[0][2] + dp_min[1][j], dp_min[0][1] + dp_min[1][j]);
					dp_max[1][j] = max(dp_max[0][2] + dp_max[1][j], dp_max[0][1] + dp_max[1][j]);
				}
			}
		else
			for (int j = 0; j < 3; j++)
			{
				if (j == 0)
				{
					dp_min[2][j] = min(dp_min[1][0] + dp_min[2][j], dp_min[1][1] + dp_min[2][j]);
					dp_max[2][j] = max(dp_max[1][0] + dp_max[2][j], dp_max[1][1] + dp_max[2][j]);
				}
				else if (j == 1)
				{
					dp_min[2][j] = min(min(dp_min[1][0] + dp_min[2][j], dp_min[1][1] + dp_min[2][j]), dp_min[1][2] + dp_min[2][j]);
					dp_max[2][j] = max(max(dp_max[1][0] + dp_max[2][j], dp_max[1][1] + dp_max[2][j]), dp_max[1][2] + dp_max[2][j]);
				}
				else
				{
					dp_min[2][j] = min(dp_min[1][2] + dp_min[2][j], dp_min[1][1] + dp_min[2][j]);
					dp_max[2][j] = max(dp_max[1][2] + dp_max[2][j], dp_max[1][1] + dp_max[2][j]);
				}
			}
	}
	cout << max(max(dp_max[num % 3][0], dp_max[num % 3][1]), dp_max[num % 3][2]) << " ";
	cout << min(min(dp_min[num % 3][0], dp_min[num % 3][1]), dp_min[num % 3][2]);
	return 0;
}