//1859����
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct info { //�ʱ� 
	int startx, starty, destx, desty, dist; //dist�� ���� �ýÿ��� �Ÿ�
};
struct bfsinfo {
	int bx, by, depth;
};
struct comp {
	/*bool operator()(info a, info  b)
	{
		if (a.dist != b.dist) return a.dist > b.dist;
		if (a.startx != b.startx)return a.startx > b.startx;
		if (a.starty != b.starty)return a.starty > b.starty;
		return false;
	}*/
	bool operator()(const info & a, const info & b)
	{
		if (a.dist != b.dist) return a.dist > b.dist;
		else
		{
			if (a.startx != b.startx) return a.startx > b.startx;
			else return a.starty > b.starty;
		}
	}
};

int N, M, fuel;
int map[20][20];
bool visit[20][20];
int taxix, taxiy;
priority_queue<info, vector<info>, comp> pq, temppq;
queue<bfsinfo> q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0 ,1, 0, -1 };
void visit_init()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = false;
	visit[taxix][taxiy] = true;

	while (!q.empty())
		q.pop();

	bfsinfo newbie = { taxix, taxiy, 0 };
	q.push(newbie);
}
int bfs(int x, int y) //�ִܰŸ� ���ϱ�
{
	visit_init();
	int ret = 0;
	while (!q.empty())
	{
		bfsinfo cur = q.front();
		q.pop();
		int curx = cur.bx;
		int cury = cur.by;
		if (curx == x && cury == y) return cur.depth;
		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
				if (map[nx][ny] == 0 && !visit[nx][ny])
				{
					/*cout << "map" << map[nx][ny] << endl;
					cout << nx << "," << ny  <<" depth"<<cur.depth<< endl;*/
					visit[nx][ny] = true;
					bfsinfo temp = { nx, ny , cur.depth + 1 };
					q.push(temp);
				}
		}
	}
	return -1;
}
void input()
{
	cin >> N >> M >> fuel;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	

	cin >> taxix >> taxiy;
	taxix--; taxiy--;
	for (int i = 0; i < M; i++)
	{
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		int k = bfs(a, b);
		//cout << k << endl;
		//cout << a << "," << b << "����" << k << endl;
		info newbie = { a, b, c, d, k};
		pq.push(newbie);
	}
}
int solve()
{
	while (!pq.empty())
	{
		info shortest = pq.top();
		pq.pop();

		int k = bfs(shortest.startx, shortest.starty);
		if (k < 0) return -1;
		fuel -= k; //���� -= ���� ����� ��������� �Ÿ�
		taxix = shortest.startx; // �ý� ��ġ �ű��
		taxiy = shortest.starty;
		//cout << "�ýð�" << taxix << "," << taxiy << "�� �̵��ϸ鼭" << k << "�Ҹ�" << "��������:" << fuel << endl;
		
		int goTodest = bfs(shortest.destx, shortest.desty);
		if (goTodest < 0)return -1;
		fuel -= goTodest;//���������� ���� �Ҹ�
		//cout << "�ýð�" << shortest.destx << "," << shortest.desty << "�� �̵��ϸ鼭" << goTodest << "�Ҹ�" << "��������:" << fuel << endl;
		if (fuel < 0) return -1; //0���� ������ ���µ��߿� �״´ٴ°� 
		fuel += goTodest * 2;
		//cout << "����������:" << fuel << endl;
		taxix = shortest.destx;
		taxiy = shortest.desty;

		while (!temppq.empty()) temppq.pop();
		while (!pq.empty())
		{
			info cur = pq.top();
			pq.pop();
			info newbie = { cur.startx, cur.starty, cur.destx, cur.desty, bfs(cur.startx, cur.starty) };
			temppq.push(newbie);
		}
		pq = temppq;
	}
	
	return fuel;
}
int main()
{
	input();
	cout << solve() << endl;
	return 0;
}