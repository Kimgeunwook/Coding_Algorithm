//1.  bfs�� �Ҷ� ���� ������ �����̷���
//    ���� ������ ũ�⸸ŭ �ѻ���Ŭ�� ����

//2. ���� ���°� Ŀ���� visit�迭�� ���ҵ� �߿���
//   �ϴ� ������ visit���� ��� ������ ����
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 987654321
int arr[100][100], section[100][100];
bool visit[100][100];
int N, sectNum = 1, answer = INF;
int dx[4] = { -1, 0 , 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue< pair<int, int>> q;
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
}
void bfs(int num)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (section[i][j] == num)
				q.push({ i,j });
			

	int depth = 0;
	while (!q.empty())
	{
		//������ Ȯ���ϱ� ���� �ѻ���Ŭ ���̴� ���� ���� ũ�⸸ŭ ��������
		int size = q.size();
		for (int k = 0; k < size; k++)
		{
			int curx = q.front().first;
			int cury = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = curx + dx[i];
				int ny = cury + dy[i];
				int nx_sect = section[nx][ny];

				if (nx >= 0 && ny >= 0 && nx < N && ny < N)
				{
					// �ٸ� ������ ������
					if (nx_sect != num && nx_sect > 0)
					{
						answer = min(answer, depth);
						return;
					}
					//�ٴ� && �湮���� �������̸�
					if (arr[nx][ny] == 0 && !visit[nx][ny])
					{
						visit[nx][ny] = true;
						q.push({ nx, ny });
					}	
				}
			}
		}
		
		depth++;

	}
}

void dfs(int x, int y)
{
	section[x][y] = sectNum;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			if (arr[nx][ny] == 1 && section[nx][ny] == 0)
				dfs(nx, ny);

	}
}

//�� �������� ��ȣ �ٿ��ֱ�
void sectioning()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (arr[i][j] == 1 && section[i][j] == 0)
			{
				dfs(i, j);
				sectNum++;
			}

}
void solve()
{
	for (int i = 1; i < sectNum; i++)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visit[i][j] = false;
		while (!q.empty()) q.pop();
		bfs(i);
	}
		
}
int main()
{
	input();
	sectioning();//�� ���� ������
	solve();
	cout << answer << endl;
	return 0;
}