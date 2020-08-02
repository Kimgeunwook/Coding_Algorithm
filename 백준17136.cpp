//17:23����
#include <iostream>
using namespace std;
#include <algorithm>
int map[11][11], temp[11][11];
int rest[6];
int _min = 987654321;
void detach(int x, int y, int size)
{
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			temp[i][j] = map[i][j];
	rest[size]++;
}
void attach(int x, int y, int size)
{
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			temp[i][j] = 0;
		
	rest[size]--;
}

bool measure(int x, int y, int size)
{
	int flag = 0;
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			if (temp[i][j] == 0) flag = 1;
	if (flag == 0 && rest[size] > 0) return true;
	else return false;			
} 

void dfs(int x, int y,int cnt)
{
	for(int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			if (temp[i][j] == 0 || cnt >= _min) continue;
			else //���� + ���
			{
				for(int  a = 5; a >= 1; a-- )
				{
					if (measure(i, j, a)) { //a������ ���� �� ������
						attach(i, j, a); // ���̰�
						dfs(i, j, cnt + 1); //�����ܰ� ���
						detach(i, j, a); //����
					}
				}
				return;
			}
		}
	// ��������
	int flag = 0;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			if (temp[i][j] == 1) flag = 1;
	if (flag == 0) {
		_min = min(_min, cnt);
	} 
}
int main()
{
	for (int i = 1; i <= 5; i++) rest[i] = 5;

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			cin >> map[i][j]; //������
			temp[i][j] = map[i][j]; // �ô� �ٿ��� �� ��
		}

	dfs(1, 1, 0); // 1,1 ���� 0�� ���� ������ ����
	if (_min == 987654321) cout << -1 << endl;
	else cout << _min << endl;
	
	return 0;
}