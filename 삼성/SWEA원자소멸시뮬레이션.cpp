//0915Ω√¿€

#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct info {
	int x, y;
	int  dir, energy;
};
vector<info> v, temp;
int m_check[4001][4001];
int dx[4] = { 1,  -1,  0,    0 };
int dy[4] = { 0,    0, -1, 1 };
int sum;
void input()
{
	int x, y, N, dir, energy;
	cin >> N;
	v.clear();
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> dir >> energy;
		info newbie = { 2 * (y + 1000), 2 * (x + 1000), dir, energy };
		v.push_back(newbie);
	}
	sum = 0;
}

void solve()
{
	for (int p = 0; p < 4100; p++)
	{
		if (v.size() == 0)break;		
		for (int i = 0; i < v.size(); i++)
		{
			info cur = v[i];
			m_check[cur.x][cur.y] = 0;
			int nx = cur.x + dx[cur.dir];
			int ny = cur.y + dy[cur.dir];
			if (nx > 4000 || nx < 0 || ny>4000 || ny < 0) continue;
			m_check[nx][ny] += cur.energy;
			info tmp = { nx,ny,cur.dir,cur.energy };
			temp.push_back(tmp);
		}

		v.clear();
		for (int k = 0; k < temp.size(); k++)
		{
			info cur = temp[k];
			if (m_check[cur.x][cur.y] != cur.energy)//∞„ƒ°∏È
			{
				sum += cur.energy;
				m_check[cur.x][cur.y] = 0;
			}
			else
			{
				v.push_back(cur);
			}
		}
		temp.clear();
	}
}

int main()
{

	int T; cin >> T;
	for (int i = 1; i <= T; i++)
	{
		input();
		solve();
		cout << "#" << i << " " << sum << endl;
	}
	return 0;

}

