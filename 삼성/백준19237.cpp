//0752 1020끝 2:28소요
//입력받을때 x,y바뀌는거없는지 -1은해야되는지 꼭체크
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
vector<ant> v_ant;//개미정보
vector<int> dir[400][4]; //방향우선순위
int antmap[400][400];//개미가 어딨는지
pair<int, int> peromonmap[400][400];//몇초남고 누구껀지
int N, M, K;
int map[20][20];//입력용
bool isdeath[400];//죽은상어인지
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
			if (map[i][j] != 0) //상어면
			{
				antmap[i][j] = map[i][j] - 1; //개미 어딨는지
				peromonmap[i][j] = { K, map[i][j] - 1}; //초기 페로몬맵
				ant newbie = { i, j, map[i][j] - 1, 0 };
				v_ant.push_back(newbie); //개미넣기
			}
		}
	
	sort(v_ant.begin(), v_ant.end(), comp); // 번호역순으로 정렬(겹쳤을때 죽이기 쉽게)
	for (int i = v_ant.size() - 1; i >= 0; i--) //방향부여
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
			continue; //죽은상어면건너뛰기
		}
		
		int cnt = 0;
		for (int i = 0; i < 4; i++) flag[i] = false;
		int nx, ny, retdir;
		for (int i = 0; i < 4; i++)
		{
			nx = v_ant[k].x + dx[i];
			ny = v_ant[k].y + dy[i];
			if(nx >= 0 && nx < N && ny >=0 && ny < N)
				if (peromonmap[nx][ny].first == 0) //페로몬없으면
				{
					cnt++;
					flag[i] = true;
				}
		}
		if (cnt > 0)
		{
			retdir = getBetterdir(v_ant[k].num, v_ant[k].dir); //우선방향얻기
		}
		else
		{
			for (int i = 0; i < 4; i++) flag[i] = false;
			for (int i = 0; i < 4; i++)
			{
				nx = v_ant[k].x + dx[i];
				ny = v_ant[k].y + dy[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)
					if (peromonmap[nx][ny].second == v_ant[k].num) //자기 페로몬이면
					{
						flag[i] = true;
					}
			}
			retdir = getBetterdir(v_ant[k].num, v_ant[k].dir);
		}

		
		antmap[v_ant[k].x][v_ant[k].y] = -1; //자기자리 0으로
		nx = v_ant[k].x + dx[retdir];
		ny = v_ant[k].y + dy[retdir];
		v_ant[k].dir = retdir;

		if (antmap[nx][ny] != -1) //누군가 있으면 바로 죽이기(어차피 번호 역순이니 그냥 죽여도된다)
		{
			isdeath[antmap[nx][ny]] = true;
		}
		antmap[nx][ny] = v_ant[k].num;
		v_ant[k].x = nx; v_ant[k].y = ny; //위치이동
	}
}
void minus_peromon() //페로몬 한개씩 줄이기
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (peromonmap[i][j].first > 0)
			{
				peromonmap[i][j].first--;
				if (peromonmap[i][j].first == 0)peromonmap[i][j].second = -1;
			}
				
}
void plus_peromon() //페로몬 뿌리기
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
bool isend() //끝났는지
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