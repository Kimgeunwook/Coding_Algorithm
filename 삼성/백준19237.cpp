//0752 1020�� 2:28�ҿ�
//�Է¹����� x,y�ٲ�°ž����� -1���ؾߵǴ��� ��üũ
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct ant {
	int x, y, num, dir;
};
bool comp(ant a, ant b)
{
	return a.num > b.num;
}
vector<ant> v_ant;//��������
vector<int> dir[400][4]; //����켱����
int antmap[400][400];//���̰� �������
pair<int, int> peromonmap[400][400];//���ʳ��� ��������
int N, M, K;
int map[20][20];//�Է¿�
bool isdeath[400];//�����������
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool flag[4];
void input()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			antmap[i][j] = -1;
			peromonmap[i][j].second = -1;
			if (map[i][j] != 0) //����
			{
				antmap[i][j] = map[i][j] - 1; //���� �������
				peromonmap[i][j] = { K, map[i][j] - 1}; //�ʱ� ��θ��
				ant newbie = { i, j, map[i][j] - 1, 0 };
				v_ant.push_back(newbie); //���ֱ̳�
			}
		}
	
	sort(v_ant.begin(), v_ant.end(), comp); // ��ȣ�������� ����(�������� ���̱� ����)
	for (int i = v_ant.size() - 1; i >= 0; i--) //����ο�
	{
		int a; cin >> a;
		v_ant[i].dir = a - 1;
	}

	for (int i = 0; i < v_ant.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int a, b, c, d; cin >> a >> b >> c >> d;
			dir[i][j] = { a - 1, b - 1, c - 1, d - 1 };
		}
	}
}
int getBetterdir(int n, int getdir)
{
	for (int i = 0; i < 4; i++)
	{
		if (flag[dir[n][getdir][i]]) return dir[n][getdir][i];
	}
}
void move()
{
	for (int k = 0; k < v_ant.size(); k++)
	{
		
		if (isdeath[v_ant[k].num])
		{
			continue; //��������ǳʶٱ�
		}
		
		int cnt = 0;
		for (int i = 0; i < 4; i++) flag[i] = false;
		int nx, ny, retdir;
		for (int i = 0; i < 4; i++)
		{
			nx = v_ant[k].x + dx[i];
			ny = v_ant[k].y + dy[i];
			if(nx >= 0 && nx < N && ny >=0 && ny < N)
				if (peromonmap[nx][ny].first == 0) //��θ������
				{
					cnt++;
					flag[i] = true;
				}
		}
		if (cnt > 0)
		{
			retdir = getBetterdir(v_ant[k].num, v_ant[k].dir); //�켱������
		}
		else
		{
			for (int i = 0; i < 4; i++) flag[i] = false;
			for (int i = 0; i < 4; i++)
			{
				nx = v_ant[k].x + dx[i];
				ny = v_ant[k].y + dy[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)
					if (peromonmap[nx][ny].second == v_ant[k].num) //�ڱ� ��θ��̸�
					{
						flag[i] = true;
					}
			}
			retdir = getBetterdir(v_ant[k].num, v_ant[k].dir);
		}

		
		antmap[v_ant[k].x][v_ant[k].y] = -1; //�ڱ��ڸ� 0����
		nx = v_ant[k].x + dx[retdir];
		ny = v_ant[k].y + dy[retdir];
		v_ant[k].dir = retdir;

		if (antmap[nx][ny] != -1) //������ ������ �ٷ� ���̱�(������ ��ȣ �����̴� �׳� �׿����ȴ�)
		{
			isdeath[antmap[nx][ny]] = true;
		}
		antmap[nx][ny] = v_ant[k].num;
		v_ant[k].x = nx; v_ant[k].y = ny; //��ġ�̵�
	}
}
void minus_peromon() //��θ� �Ѱ��� ���̱�
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (peromonmap[i][j].first > 0)
			{
				peromonmap[i][j].first--;
				if (peromonmap[i][j].first == 0)peromonmap[i][j].second = -1;
			}
				
}
void plus_peromon() //��θ� �Ѹ���
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (antmap[i][j] != -1)
				peromonmap[i][j] = { K, antmap[i][j] };

}
void solve()
{
	move();
	minus_peromon();
	plus_peromon();
}
bool isend() //��������
{
	int cnt = 0;
	for (int i = 0; i < M; i++)
		if (!isdeath[i])cnt++;
	if (cnt == 1)
		return true;
	else
		return false;
}
int main()
{
	input();
	int answer = 0;
	while (1)
	{
		if (answer > 1000)
		{
			cout << -1 << endl;
			break;
		}
		if (isend())
		{
			cout << answer << endl;
			break;
		}
		solve();
		answer++;
	}
	return 0;
}