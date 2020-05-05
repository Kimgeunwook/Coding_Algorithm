#include <iostream>
#include <stdio.h>
using namespace std;
bool map[5][8], diff[5], use[6], temp[8];
int num, a, b, sum = 0;
void rotate(int a, int b)
{
	use[a] = 1;
	for (int i = 0; i < 8; i++)
		temp[i] = map[a][i];

	if (b == 1)
	{
		map[a][0] = temp[7];
		for (int i = 1; i < 8; i++)
		{
			map[a][i] = temp[i - 1];
		}
	}
	else
	{
		map[a][7] = temp[0];
		for (int i = 0; i < 7; i++)
		{
			map[a][i] = temp[i + 1];
		}
	}

	if ((a - 1 >= 1) && (diff[a - 1] == 1) && (use[a - 1] == 0))
		if (b == 1)
			rotate(a - 1, -1);
		else
			rotate(a - 1, 1);

	if ((a + 1 <= 4) && (diff[a] == 1) && (use[a + 1] == 0))
		if (b == 1)
			rotate(a + 1, -1);
		else
			rotate(a + 1, 1);

}
void is_different()
{
	if (map[1][2] != map[2][6])
		diff[1] = 1;
	else
		diff[1] = 0;

	if (map[2][2] != map[3][6])
		diff[2] = 1;
	else
		diff[2] = 0;

	if (map[3][2] != map[4][6])
		diff[3] = 1;
	else
		diff[3] = 0;
}
int main() {
	for (int i = 1; i <= 4; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &map[i][j]);

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		is_different();
		cin >> a >> b;
		rotate(a, b);

		for (int i = 1; i < 5; i++)
			use[i] = 0;
	}


	if (map[1][0]) sum += 1;
	if (map[2][0]) sum += 2;
	if (map[3][0]) sum += 4;
	if (map[4][0]) sum += 8;
	cout << sum;
	return 0;
}