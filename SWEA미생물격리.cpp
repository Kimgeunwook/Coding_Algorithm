#include <iostream>
using namespace std;
#include <queue>
struct info {
	int x, y, dir, num;
};
int T, N, M, K;//�� ����  ,  ��ũ��   ,   �ð�  ,  ������
//1 ��    2 ��   3 ��  4��
int dx[5] = {0, -1, 1, 0, 0 };
int dy[5] = {0, 0, 0, -1, 1};
int rdir[5] = { 0, 2, 1, 4, 3 };
queue<info> q;
queue<info> map[101][101];
int visit[101][101];
void simulation()
{
	
	for (int i = 0; i < M; i++)
	{
		//cout << q.size() << "###################" << endl;
		while (!q.empty())
		{
			/*cout << endl;
			cout << i<<"����" << endl;*/
			
			info cur = q.front();
			/*cout << map[cur.x][cur.y].size() << endl;
			cout << cur.x << "," << cur.y <<","<< cur.dir<<","<< cur.num<< endl;*/
			q.pop();
			if (cur.x + dx[cur.dir] == 0 || cur.x + dx[cur.dir] == N - 1 || cur.y + dy[cur.dir] == 0 || cur.y + dy[cur.dir] == N - 1) //���������̸�
			{
				//cout << "2��" << endl;
				map[cur.x][cur.y].pop();
				info temp = { cur.x + dx[cur.dir], cur.y + dy[cur.dir], rdir[cur.dir], cur.num / 2 };
				if (cur.num / 2 != 0)
				{
					map[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]].push(temp);
					visit[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]] = 1;
				}
			}
			else
			{
				if (visit[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]] == 0) //  ��ĭ�̸�
				{
				//	cout << "3��" << endl;
					map[cur.x][cur.y].pop();
					info temp = { cur.x + dx[cur.dir], cur.y + dy[cur.dir], cur.dir, cur.num };
					map[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]].push(temp);
					visit[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]] = 1;
				}
				else // �ٸ������̶� ��������
				{
					visit[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]] = 2;
				//	cout << "4��" << endl;
					map[cur.x][cur.y].pop();
					info temp = { cur.x + dx[cur.dir], cur.y + dy[cur.dir], cur.dir, cur.num };
					map[cur.x + dx[cur.dir]][cur.y + dy[cur.dir]].push(temp);
					
				}
			}
		}
		for(int i = 0; i <= N - 1; i++)
			for (int j = 0; j <= N - 1; j++)
			{
				if (visit[i][j] == 2) //��ģ��
				{
					//cout << "��ģ��:" << i << "," << j << endl;
					int sum = 0;
					int max_n = 0, max_d;
					while (!map[i][j].empty())
					{
						info cur = map[i][j].front();
						map[i][j].pop();
						sum += cur.num;

						if (cur.num > max_n)
						{
							max_n = cur.num;
							max_d = cur.dir;
						}
					}
					info temp = { i, j , max_d, sum };
					map[i][j].push(temp);
					q.push(temp);
				}
				else if (visit[i][j] == 1) //��ġ�� �ʰ� üũ�س�����
				{
					q.push(map[i][j].front());
				}
				
			}
		for (int i = 0; i <= N - 1; i++)
			for (int j = 0; j <= N - 1; j++)
				visit[i][j] = 0;
	}
}
////////////////////////visit�ʱ�ȭ
int main()
{
	cin >> T;
	for (int test = 1; test <= T; test++)
	{
		cin >> N >> M >> K;

		int a, b, c, d;
		for (int i = 0; i < K; i++)
		{
			cin >> a >> b >> c >> d;
			info newbie = { a, b, d, c };
			q.push(newbie);
			map[a][b].push(newbie);
		}
		simulation();
		int sum = 0;
		while (!q.empty()) {
			sum += q.front().num;
			q.pop();
		}
		cout<<"#"<<2<<" " << sum << endl;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				while (!map[i][j].empty())
				{
					map[i][j].pop();
				}
			}
	}
	
	return 0;
}