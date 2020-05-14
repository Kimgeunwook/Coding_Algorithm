#include <iostream>
using namespace std;
bool map[101][101];
bool answer[101][101];
int main()
{
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
		{
			cin >> map[i][j];
		}

	for (int k = 1; k <= num; k++)
		for (int i = 1; i <= num; i++)
			for (int j = 1; j <= num; j++)
			{
				if ((map[i][k] && map[k][j]) || map[i][j])
				{
					answer[i][j] = 1;
					map[i][j] = 1;
				}

			}
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}