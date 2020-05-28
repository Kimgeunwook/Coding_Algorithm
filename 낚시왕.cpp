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
queue<SHARK> pqcol; //열 크기로 정렬(열 같으면 행보기)

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
		//answer더해줄거 더해주고 pqcol -> pq
		while (!pqcol.empty())
		{
			if (k == pqcol.front().c && flag == 0)
			{
				//cout << "상어잡음" << pqcol.top().r << "," << pqcol.top().r << "," << pqcol.top().z << endl;
				flag = 1;
				answer += pqcol.front().z;
				pqcol.pop();
				continue;
			}
			temp.push(pqcol.front());
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
			//@@@@@@@@@@@@@@여기서 어떤 조치로 x,y좌표 바꾸고
			int temp_speed = cur_speed;
			while (temp_speed)
			{
				if (cur_dir == 1)//위
				{
					if (cur_x == 1)
					{
						cur_dir = 2;
						cur_x += 1;
					}
					else
						cur_x -= 1;
				}
				else if (cur_dir == 2)//아래
				{
					if (cur_x == R)
					{
						cur_dir = 1;
						cur_x -= 1;
					}
					else
						cur_x += 1;
				}
				else if (cur_dir == 3)//오
				{
					if (cur_y == R)
					{
						cur_dir = 4;
						cur_y -= 1;
					}
					else
						cur_y += 1;
				}
				else if (cur_dir == 4)//왼
				{
					if (cur_y == 1)
					{
						cur_dir = 3;
						cur_y += 1;
					}
					else
						cur_y -= 1;
				}
				temp_speed--;
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