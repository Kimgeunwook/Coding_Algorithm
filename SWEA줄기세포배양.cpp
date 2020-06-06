#include <iostream>
#include <queue>
using namespace std;
struct info {
	int state, life, acttime, unacttime; // 상태(-1빈칸 0비활성 1활성 2죽음)  /   생명수치   /  활성시간   / 비활성시간
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
		for (int i = 0; i < 350; i++)   //맵 초기화
			for (int j = 0; j < 350; j++)
			{
				info newbie = { -1,0,0,0 };
				map[i][j] = newbie;
			}

		cin >> N >> M >> K;
		for (int i = 150; i < 150 + N; i++)  //초기 입력받은 애들 넣어주기
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
			for (int i = 0; i < 350; i++)  //비활성화 애들 시간 깎아주고 시간0되면 활성화에 넣어주기
				for (int j = 0; j < 350; j++)
				{
					if (map[i][j].state == 0) //비활성화면
					{
						if (map[i][j].unacttime > 0)
							map[i][j].unacttime--;
						if (map[i][j].unacttime == 0)
							map[i][j].state = 1;
					}
					else if (map[i][j].state == 1) //활성화면
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
								if (map[cur.x + i][cur.y + j].state == -1) // 4방향 탐색했을때 빈칸이면
								{
									map[cur.x + i][cur.y + j].state = 0;
									map[cur.x + i][cur.y + j].life = map[cur.x][cur.y].life;
									map[cur.x + i][cur.y + j].acttime = map[cur.x][cur.y].life;
									map[cur.x + i][cur.y + j].unacttime = map[cur.x][cur.y].life;
								}
								else if (map[cur.x + i][cur.y + j].state == 0 && map[cur.x + i][cur.y + j].life == map[cur.x + i][cur.y + j].unacttime) // 방금 막 비활성화 상태에 들어간애면
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