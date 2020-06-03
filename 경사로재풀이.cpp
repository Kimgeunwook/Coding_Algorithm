#include <iostream>
#include <math.h>
using namespace std;
int N, L;
int map[100][100];
int map2[100][100];
int sum = 0;
int visit[100];
void simulation(int map[100][100])
{
	//����
	for (int row = 0; row < N; row++)
	{
		int temp = map[row][0]; //�������
		int life = 1 ;
		for (int k = 1; k < N; k++)
		{
			if (abs(temp - map[row][k] > 1)) // �������� 1ĭ�ʰ��� ���͵�����
			{
				life = -1;
				break;
			}
			if (map[row][k] == temp)
				life++;				
			else  if(map[row][k] > temp)
			{
				if (life >= L)
				{
					life = 1;
					temp = map[row][k];
				}
				else
				{
					life = -1;
					break;
				}
			}
			else if (temp > map[row][k])
			{
				if (life < 0)
					break;
				life = - L + 1;
				temp = map[row][k];
			}
		}

		if (life >= 0)
			sum++;
	}

}
int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map2[i][j] = map[N - 1 - j][i];
		
	
	simulation(map);
	simulation(map2);
	cout << sum << endl;
	return 0;
}