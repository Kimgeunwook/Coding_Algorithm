#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int counts = 0;
int map[101][101]; //전체맵(map[col][row])
void search(int x, int y)
{

	int search_count = 0;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if ((i == 0 && j == 0) || (i == -1 && j == -1) || (i == -1 && j == 1) || (i == 1 && j == -1) || (i == 1 && j == 1))
				continue;
			else
			{
				if (map[x + i][y + j] == 1)
				{
					if (map[x][y] == 1)
						counts++;
					map[x][y] = 7;
					search(x + i, y + j);
				}
				else
					search_count++;

				if (i == 1 && j == 0 && search_count == 4)
				{
					map[x][y] = 7;
					counts++;
				}
			}

		}
	}

}

int main()
{

	int row, col; // row는 가로 col은 세로
	int num;//직사각형 몇개 받을건지
	int left_x, left_y, right_x, right_y;

	vector<int> pq;
	cin >> col >> row >> num;
	for (int i = 0; i <= col + 1; i++)
		for (int j = 0; j <= row + 1; j++)
		{
			if (i == 0 || j == 0 || i == col + 1 || j == row + 1)
				map[i][j] = 9;
			else
				map[i][j] = 1;
		}

	for (int i = 0; i < num; i++)
	{
		cin >> left_x >> left_y >> right_x >> right_y;
		for (int k = left_y + 1; k <= right_y; k++)
			for (int w = left_x + 1; w <= right_x; w++)
			{
				map[k][w] = 9;
			}
	}

	for (int i = 1; i <= col; i++)
		for (int j = 1; j <= row; j++)
			if (map[i][j] == 1)
			{
				counts = 0;
				search(i, j);
				pq.push_back(counts);
			}
	sort(pq.begin(), pq.end());
	cout << pq.size() << endl;
	for (int i = 0; i != pq.size(); i++)
		cout << pq[i] << " ";

	return 0;
}
