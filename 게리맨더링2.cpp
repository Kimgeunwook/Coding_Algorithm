#include <iostream>
using namespace std;
#include <queue>
int map[21][21];
int N;
vector<int> v[21];
void check(int x, int  y, int d1, int d2)
{
	for (int i = 1; i <= 20; i++)
		v[i].clear();

	//�� -> ��
	for (int i = 0; i <= d1; i++)
		v[x + i].push_back(y - i);

	//�� -> ��
	for (int i = 1; i <= d2; i++)
		v[x + d1 + i].push_back(y - d1 + i);
	
	//�� -> ��
	for (int i = 0; i <= d2; i++)
		v[x + i].push_back(y + i);

	//�� - > ��
	for (int i = 1; i <= d1; i++)
		v[x + d2 + i].push_back(y + d2 - i);

	
}
int seperate(int x, int y, int d1, int d2)
{
	check(x, y, d1, d2);
	int num[6] = {0,};
	//////1,2,3,4�����ű� ���� �ֿ����� ���� �� ���ະ�� ���������� ĳġ�ϸ� ��
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (v[i].size() == 0)
			{
				if (i < x && j <= y)
					num[1] += map[i][j];
					
				
				else if (i < x && j > y)
					num[2] += map[i][j];
				
				else if (i > x + d1 + d2 && j < y - d1 + d2)
					num[3] += map[i][j];
				
				else
					num[4] += map[i][j];
					
			}
			else
			{
				if (i < x + d1 && j < v[i][0])
					num[1] += map[i][j];
				
				else if (i <= x + d2 && j > v[i][1])
					num[2] += map[i][j];
				
				else if (i >= x + d1 && j < v[i][0])
					num[3] += map[i][j];
				
				else if (i > x + d2 && j > v[i][1])
					num[4] += map[i][j];
				
				else
					num[5] += map[i][j];
					
			}
		}

	int max = num[1];
	int min = num[1];
	for (int i = 2; i <= 5; i++)
	{
		if (num[i] > max)
			max = num[i];
		if (num[i] < min)
			min = num[i];
	}
	return max - min;
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];
	
	int ret = 987654321;
	for(int i = 1; i <= N - 2; i++)
		for (int j = 2; j <= N - 1; j++)
			for (int d1_d2 = 2; d1_d2 <= N - i; d1_d2++)
				for (int d1 = 1; d1 <= d1_d2 - 1; d1++)
				{
					int d2 = d1_d2 - d1;
					////#############################d1 d2�� ��� ���� üũ
					if (j - d1 >= 1 && j + d2 <= N)
					{
						//cout << i << "," << j << "," << d1 << ","<<d2 << endl;
						if (seperate(i, j, d1, d2) < ret)
							ret = seperate(i, j, d1, d2);
					}
					
				}
	cout << ret;
	return 0;
}