#include <iostream>
using namespace std;
int N, M;
int curx, cury, dir; //�κ���ġ, ����
int sum = 0;//���� ����
int map[50][50] , visit[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void simulation()
{
	while (1)
	{
		int flag = 0;
		for (int i = 0; i < 4; i++) //4���� ȸ��
		{
			int next_dir = (dir + 3) % 4; // �������� ȸ��
			dir = next_dir;
			if (map[curx + dx[dir]][cury + dy[dir]] == 0 && visit[curx + dx[dir]][cury + dy[dir]] == 0)//��ĭ�̰� �Ȱ������̸�
			{
				flag++;
				visit[curx + dx[dir]][cury + dy[dir]] = 1;
				map[curx + dx[dir]][cury + dy[dir]] == 2; // û�ҷ� üũ
				sum++;
				curx += dx[dir];
				cury += dy[dir];
				break;
			}
		}
		if (flag == 0) //����������
		{
			if (curx - dx[dir] >= 0 && curx - dx[dir] < N && cury - dy[dir] >= 0 && cury - dy[dir] < M && map[curx - dx[dir]][cury - dy[dir]] != 1)//�����Ҽ�������
			{
				curx -= dx[dir];
				cury -= dy[dir];
			}
			else
				break;
		}
		
	}
}
int main()
{
	cin >> N >> M;
	cin >> curx >> cury >> dir;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];


	
	map[curx][cury] = 2; //����ĭ û��
	sum++; // û�Ұ��� ++
	visit[curx][cury] = 1;// for ������visit

	simulation();
	cout << sum << endl;
	return 0;
}