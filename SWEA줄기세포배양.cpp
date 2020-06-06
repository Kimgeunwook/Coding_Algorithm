#include <iostream>
#include <queue>
using namespace std;
struct info {
	int state, life, acttime, unacttime; // ����(-1��ĭ 0��Ȱ�� 1Ȱ�� 2����)  /   �����ġ   /  Ȱ���ð�   / ��Ȱ���ð�
};
struct acting {
	int x, y, life;
};
int test_case;
int T, N, M, K, n;
info map[350][350];

queue<acting> act;
int main()
{
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		for (int i = 0; i < 350; i++)   //�� �ʱ�ȭ
			for (int j = 0; j < 350; j++)
			{
				info newbie = { -1,0,0,0 };
				map[i][j] = newbie;
			}

		cin >> N >> M >> K;
		for (int i = 150; i < 150 + N; i++)  //�ʱ� �Է¹��� �ֵ� �־��ֱ�
		{
			for (int j = 150; j < 150 + M; j++)
			{
				cin >> n;
				if (n > 0)
				{
					info newbie = { 0, n, n , n };
					map[i][j] = newbie;
				}
			}
		}

		int time = 0;
		while (time < K)
		{
			for (int i = 0; i < 350; i++)  //��Ȱ��ȭ �ֵ� �ð� ����ְ� �ð�0�Ǹ� Ȱ��ȭ�� �־��ֱ�
				for (int j = 0; j < 350; j++)
				{
					if (map[i][j].state == 0) //��Ȱ��ȭ��
					{
						if (map[i][j].unacttime > 0)
							map[i][j].unacttime--;
						if (map[i][j].unacttime == 0)
							map[i][j].state = 1;
					}
					else if (map[i][j].state == 1) //Ȱ��ȭ��
					{
						if (map[i][j].acttime > 0)
						{
							acting newbie = { i,j,map[i][j].life };
							act.push(newbie);
							map[i][j].acttime--;
						}
						if (map[i][j].acttime == 0)
							map[i][j].state = 2;
					}

				}
			while (!act.empty())
			{
				acting cur = act.front();
				act.pop();
				for (int i = -1; i < 2; i++)
					for (int j = -1; j < 2; j++)
						if (!(i == 0 && j == 0) && (i * j == 0))
							if (cur.x + i >= 0 && cur.y + i < 350 && cur.x + j >= 0 && cur.y + j < 350)
							{
								if (map[cur.x + i][cur.y + j].state == -1) // 4���� Ž�������� ��ĭ�̸�
								{
									map[cur.x + i][cur.y + j].state = 0;
									map[cur.x + i][cur.y + j].life = map[cur.x][cur.y].life;
									map[cur.x + i][cur.y + j].acttime = map[cur.x][cur.y].life;
									map[cur.x + i][cur.y + j].unacttime = map[cur.x][cur.y].life;
								}
								else if (map[cur.x + i][cur.y + j].state == 0 && map[cur.x + i][cur.y + j].life == map[cur.x + i][cur.y + j].unacttime) // ��� �� ��Ȱ��ȭ ���¿� ���ָ�
								{
									if (map[cur.x][cur.y].life > map[cur.x + i][cur.y + j].life)
									{
										map[cur.x + i][cur.y + j].life = map[cur.x][cur.y].life;
										map[cur.x + i][cur.y + j].acttime = map[cur.x][cur.y].life;
										map[cur.x + i][cur.y + j].unacttime = map[cur.x][cur.y].life;
									}
								}
							}

			}


			time++;
		}
		int ret = 0;
		for (int i = 0; i < 350; i++)
			for (int j = 0; j < 350; j++)
				if (map[i][j].state == 1 || map[i][j].state == 0)
					ret++;
		cout<<"#"<< test_case<<" " << ret << endl;
	}

	
	return 0;
}