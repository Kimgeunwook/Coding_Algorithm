#include <iostream>
#include <queue>
using namespace std;
int visit[102][102];
int R, C, M;//행  열  상어개체수
int r, c, s, d, z;// 위치r 위치c 속력 방향 크기
int cur_x, cur_y, cur_speed, cur_dir, cur_size;
int flag = 0, answer = 0;
bool mem[2200];//이동칸 계산하기위해
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

priority_queue <SHARK, vector<SHARK>, compare> pq; //사이즈 내림차순
queue<SHARK> temp; //사이즈 내림차순
priority_queue <SHARK, vector<SHARK>, compare2> pqcol; //열 크기로 정렬(열 같으면 행보기)

int main()
{
	cin >> R >> C >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> s >> d >> z; //상어 크기별로 입력
		SHARK next = { r,c,s,d,z };
		pqcol.push(next);
	}

	for (int k = 1; k <= C; k++)
	{
		flag = 0;
		//상어 잡는 부분
		while (!pqcol.empty())
		{
			if (k == pqcol.top().c && flag == 0)
			{
				//cout << "상어잡음" << pqcol.top().r << "," << pqcol.top().c << "," << pqcol.top().z << endl;
				flag = 1;
				answer += pqcol.top().z;
				pqcol.pop();
				continue;
			}
			temp.push(pqcol.top());
			pqcol.pop();
		}

		//visit배열 초기화
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				visit[i][j] = 0;


		//@@@@@@@@상어들 이동시키기 temp -> pqㄱㄱㄱ
		while (!temp.empty())
		{
			cur_x = temp.front().r;
			cur_y = temp.front().c;
			cur_speed = temp.front().s;
			cur_dir = temp.front().d;
			cur_size = temp.front().z;
			int next_location;
			if (cur_dir == 1)//위
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
			else if (cur_dir == 2)//아래
			{
				if (cur_x + cur_speed > R)
				{
					next_location = (cur_x + cur_speed - R) % (R - 1);
					if (((cur_x + cur_speed - R) / (R - 1)) % 2 == 0) //역
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
			else if (cur_dir == 3)//오
			{
				if (cur_y + cur_speed > C)
				{
					next_location = (cur_y + cur_speed - C) % (C - 1);
					if (((cur_y + cur_speed - C) / (C - 1)) % 2 == 0) // 역방향
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
			else if (cur_dir == 4)//왼
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

		//pqcol초기화
		while (!pqcol.empty())
		{
			pqcol.pop();
		}

		// 이동후 같은칸에 있는애들 거르기
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