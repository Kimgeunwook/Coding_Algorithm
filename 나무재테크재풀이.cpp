#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TREE {
	int x, y, age;
};
int N, M, K; //맵크기, 나무수, 몇년뒤인지
int map[11][11];
int A[11][11];
queue<TREE> dq; //현재나무들
queue<TREE> nex; //내년에 넘어갈 나무들
queue<TREE> fall;
vector<TREE> dead;
int main()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
			map[i][j] = 5;
		}
			

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		TREE temp = {a, b, c};
		dq.push(temp);
	}

	for (int i = 0; i < K; i++)
	{


		//봄 @@@@@next초기화위치
		while (!nex.empty()) nex.pop();
		dead.clear();
		while (!dq.empty())
		{
			TREE cur = dq.front();
			if (map[cur.x][cur.y] >= cur.age)
			{
				map[cur.x][cur.y] -= cur.age;
				TREE next = { cur.x, cur.y, cur.age + 1 };
				nex.push(next);
				fall.push(next);
			}
			else
			{
				TREE deadtree = { cur.x, cur.y, cur.age };
				dead.push_back(deadtree);
			}
			dq.pop();
		}


		//여름
		for (int k = 0; k < dead.size(); k++)
		{
			TREE cur = dead[k];
			map[cur.x][cur.y] += cur.age / 2;
		}


		//가을
		while (!dq.empty()) dq.pop();
		while (!fall.empty())
		{
			TREE cur = fall.front();
			if (cur.age % 5 == 0)
			{
				for (int a = -1; a < 2; a++)
					for (int b = -1; b < 2; b++)
						if (!(a == 0 && b == 0) && cur.x + a >= 1 && cur.x + a <= N && cur.y + b >= 1 && cur.y + b <= N)
						{
							TREE next = { cur.x + a, cur.y + b, 1 };
							dq.push(next);
						}
			}
			fall.pop();
		}


		//겨울
		for (int a = 1; a <= N; a++)
			for (int b = 1; b <= N; b++)
				map[a][b] += A[a][b];


		while (!nex.empty())
		{
			dq.push(nex.front());
			nex.pop();
		}
	}

	cout << dq.size() << endl;
	return 0;
}