#include <iostream>
#include <queue>
using namespace std;
int visit[102][102];
int R, C, M;//��  ��  ��ü��
int r, c, s, d, z;// ��ġr ��ġc �ӷ� ���� ũ��
int cur_x, cur_y, cur_speed, cur_dir, cur_size;
int flag = 0, answer = 0;
bool mem[2200];//�̵�ĭ ����ϱ�����
struct SHARK {
	int r, c, s, d, z;
};
struct compare {
	bool operator()(SHARK a, SHARK b)
	{
		return a.z < b.z;
	}
};
struct compare2 {
	bool operator()(SHARK a, SHARK b)
	{
		if (a.c != b.c)
			return a.c > b.c;
		else if (a.c == b.c)
			return a.r > b.r;
	}
};

priority_queue <SHARK, vector<SHARK>, compare> pq; //������ ��������
queue<SHARK> temp; //������ ��������
priority_queue <SHARK, vector<SHARK>, compare2> pqcol; //�� ũ��� ����(�� ������ �ຸ��)

int main()
{
	cin >> R >> C >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> s >> d >> z; //��� ũ�⺰�� �Է�
		SHARK next = { r,c,s,d,z };
		pqcol.push(next);
	}

	for (int k = 1; k <= C; k++)
	{
		flag = 0;
		//��� ��� �κ�
		while (!pqcol.empty())
		{
			if (k == pqcol.top().c && flag == 0)
			{
				//cout << "�������" << pqcol.top().r << "," << pqcol.top().c << "," << pqcol.top().z << endl;
				flag = 1;
				answer += pqcol.top().z;
				pqcol.pop();
				continue;
			}
			temp.push(pqcol.top());
			pqcol.pop();
		}

		//visit�迭 �ʱ�ȭ
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				visit[i][j] = 0;


		//@@@@@@@@���� �̵���Ű�� temp -> pq������
		while (!temp.empty())
		{
			cur_x = temp.front().r;
			cur_y = temp.front().c;
			cur_speed = temp.front().s;
			cur_dir = temp.front().d;
			cur_size = temp.front().z;
			int next_location;
			if (cur_dir == 1)//��
			{
				if (cur_x - cur_speed < 1)
				{
					cur_x = R - cur_x + 1;
					next_location = (cur_x + cur_speed - R) % (R - 1);
					if (((cur_x + cur_speed - R) / (R - 1)) % 2 == 0)
					{
						cur_x = next_location + 1;
						cur_dir = 2;
					}
					else
					{
						cur_x = R - next_location;
					}
				}
				else
				{
					cur_x -= cur_speed;
				}
			}
			else if (cur_dir == 2)//�Ʒ�
			{
				if (cur_x + cur_speed > R)
				{
					next_location = (cur_x + cur_speed - R) % (R - 1);
					if (((cur_x + cur_speed - R) / (R - 1)) % 2 == 0) //��
					{
						cur_x = R - next_location;
						cur_dir = 1;
					}
					else
					{
						cur_x = next_location + 1;
					}
				}
				else
				{
					cur_x = cur_x + cur_speed;
				}
			}
			else if (cur_dir == 3)//��
			{
				if (cur_y + cur_speed > C)
				{
					next_location = (cur_y + cur_speed - C) % (C - 1);
					if (((cur_y + cur_speed - C) / (C - 1)) % 2 == 0) // ������
					{
						cur_y = C - next_location;
						cur_dir = 4;
					}
					else
					{
						cur_y = next_location + 1;
					}
				}
				else
				{
					cur_y = cur_y + cur_speed;
				}
				
			}
			else if (cur_dir == 4)//��
			{
				if (cur_y - cur_speed < 1)
				{
					cur_y = C - cur_y + 1;
					next_location = (cur_y + cur_speed - C) % (C - 1);
					if (((cur_y + cur_speed - C) / (C - 1)) % 2 == 0) 
					{
						cur_y = next_location + 1;
						cur_dir = 3;
					}
					else
					{
						cur_y = C - next_location;
					}
				}
				else
				{
					cur_y -= cur_speed;
				}
			}
			SHARK newbie = { cur_x, cur_y , cur_speed, cur_dir, cur_size };
			pq.push(newbie);
			temp.pop();
		}

		//pqcol�ʱ�ȭ
		while (!pqcol.empty())
		{
			pqcol.pop();
		}

		// �̵��� ����ĭ�� �ִ¾ֵ� �Ÿ���
		while (!pq.empty())
		{
			cur_x = pq.top().r;
			cur_y = pq.top().c;
			cur_speed = pq.top().s;
			cur_dir = pq.top().d;
			cur_size = pq.top().z;

			if (visit[cur_x][cur_y])
			{
				pq.pop();
			}
			else
			{
				visit[cur_x][cur_y] = 1;
				SHARK tem = { cur_x,cur_y,cur_speed,cur_dir,cur_size };
				pqcol.push(tem);
				pq.pop();
			}
		}
	}
	cout << answer << endl;


	return 0;
}