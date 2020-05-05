#include <iostream>
using namespace std;
int dice[11], max_score = 0,location[5];
#define N 4
#define R 10
int selected[R];
int map[2][61] = { { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,-1,-1,-1,-1,-1,//0~25 
	13,16,19,25,30,35,40,-1,-1,-1,-1,-1,//26~37  
	22,24,25,30,35,40,-1,-1,-1,-1,-1,//38~48 
	28,27,26,25,30,35,40,-1,-1,-1,-1,-1}//49~60  

	,{ 0, } };

//1.���� �̹� ���������� 
//2.������ �ﰢ���̸� ���ΰ�������
//3.�������� 
//4.�̵��ϱ����� ��ü�迭���� location��ġ üũ���ְ� location���� �ٲ��ֱ�
int cnt = 0;
void dfs(int depth)
{
	if (R == depth) 
	{// ��� ���� �Ǿ���
		cnt++;
		for (int i = 0; i < 5; i++)
			location[i] = 0;

		int now_score = 0;
		for (int i = 1; i <= R; i++)
		{
			if (map[0][location[selected[i]]] == -1)//�̹� �������϶�
			{
				cout << "�̹� ������" <<location[selected[i]]<< endl;
				return;
			}
				
			if (map[0][location[selected[i]]] == 10) //�������� 10,20,30�̸� check=0���ְ� ����� �ٲ��ֱ�
			{
				map[1][location[selected[i]]] = 0;
				location[selected[i]] += 20;
			}
			if (map[0][location[selected[i]]] == 20)
			{
				map[1][location[selected[i]]] = 0;
				location[selected[i]] += 27;
			}
			if (map[0][location[selected[i]]] == 30)
			{
				map[1][location[selected[i]]] = 0;
				location[selected[i]] += 33;
			}
			if (map[1][location[selected[i]] + dice[i]] == 1)//��ģ ���
			{
				cout << "����" << endl;
				return;
			}
				
			else
			{
				map[1][location[selected[i]]] = 0;//�̵��� ��ġ �ڸ��÷��� 0���� ������ֱ�
				if (map[0][location[selected[i]] + dice[i]] != -1) //�̵��� �ڸ��� �������� �ƴϸ�
				{
					now_score += map[0][location[selected[i]] + dice[i]];
					location[selected[i]] += dice[i];
					map[1][location[selected[i]]] = 1;
				}
				else
					location[selected[i]] += dice[i];
			}
		//	cout << cnt << endl;
		}
		if (now_score > max_score) 
			max_score = now_score;
		return;
	}
	for (int i = 1; i <= N; i++) 
	{
		selected[depth + 1] = i;
		dfs(depth + 1);
	}
}

int main()
{
	for (int i = 1; i <= 10; i++)
		cin >> dice[i];
	dfs(0);
	cout << max_score << endl;
	return 0;
}