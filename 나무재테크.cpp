#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
int N, M, K;
int map[10][10], vitamin[10][10]; // 주맵   입력양분맵

struct tree
{
	int x;
	int y;
	int age;
};
struct compare {
	bool operator()(tree a, tree b)
	{
		return a.age > b.age;
	}
};
queue<tree> newbie, curyear, mother,dead, nextyear; //번식 올해 엄마 내년
priority_queue<tree, vector<tree>, compare> pqtree;

int main()
{
	cin >> N >> M >> K; //맵크기   나무개수   몇년지날건지

	for (int i = 0; i < N; i++) //처음 나무 양분5로 초기화
		for (int j = 0; j < N; j++)
			map[i][j] = 5;

	for (int i = 0; i < N; i++) //겨울양분
		for (int j = 0; j < N; j++)
			cin >> vitamin[i][j];

	for (int i = 0; i < M; i++)//////////////나무 위치 입력받기
	{
		int x, y, age;
		cin >> x >> y >> age;
		tree a = { x - 1,y - 1,age };
		pqtree.push(a);
	}

	//올해 큐 만들기
	while (!pqtree.empty())
	{
		curyear.push(pqtree.top());
		pqtree.pop();
	} 
	
	for (int p = 0; p < K; p++)////////K번반복
	{
		int curx, cury, curage;
		tree temp;

		//뉴비들 돌리는타임
		/*cout << "뉴비돌리는중"<<p << endl;
		cout << newbie.size() << endl;
		cout << curyear.size() << endl;
		cout << nextyear.size() << endl;*/
		while (!nextyear.empty())
		{
			nextyear.pop();
		}
		while (!dead.empty())
		{
			dead.pop();
		}
		while (!newbie.empty())
		{
			curx = newbie.front().x;
			cury = newbie.front().y;
			curage = newbie.front().age;
			///////////////////
			if (curage <= map[curx][cury]) //양분 먹을수있다.
			{
				map[curx][cury] -= 1;
				curage += 1;
				temp = { curx,cury,curage };
				nextyear.push(temp);
			}
			else //양분 먹을수 없다.
			{
				temp = { curx, cury, curage };
				dead.push(temp);
			}
			////////////////
			newbie.pop();
		}

		//올해애들 돌리기
		/*cout << "올해애들돌리는중"<<p << endl;
		cout << newbie.size() << endl;
		cout << curyear.size() << endl;
		cout << nextyear.size() << endl;*/
		while (!mother.empty())
		{
			mother.pop();
		}
		while (!curyear.empty())
		{
			curx = curyear.front().x;
			cury = curyear.front().y;
			curage = curyear.front().age;
			if (curage <= map[curx][cury]) //양분 먹을수있다.
			{
				map[curx][cury] -= curage;
				curage += 1;
				temp = {curx,cury,curage};
				if (curage % 5 == 0)
				{
					mother.push(temp);
				}
				nextyear.push(temp);
			}
			else //양분 먹을수 없다.
			{
				temp = { curx, cury, curage};
				dead.push(temp);
			}
			curyear.pop();
		}

		//번식엄마타임
		/*cout << "번식돌리는중" <<p<< endl;
		cout << newbie.size() << endl;
		cout << curyear.size() << endl;
		cout << nextyear.size() << endl;*/
		while (!newbie.empty())
		{
			newbie.pop();
		}
		while (!mother.empty())
		{
			curx = mother.front().x;
			cury = mother.front().y;
			for (int a = -1; a < 2; a++)
				for (int b = -1; b < 2; b++)
					if (!(a == 0 && b == 0) && curx + a >= 0 && curx + a < N && cury + b >= 0 && cury + b < N)
					{
						tree add = { curx + a, cury + b,1 };
						newbie.push(add);
					}

			mother.pop();
		}

		//죽은애들->양분타임
		/*cout << "죽은애들 부활타임"<<p << endl;
		cout << newbie.size() << endl;
		cout << curyear.size() << endl;
		cout << nextyear.size() << endl;*/
		while (!dead.empty())
		{
			curx = dead.front().x;
			cury = dead.front().y;
			curage = dead.front().age;
			map[curx][cury] += curage / 2;
			dead.pop();
		}

		//보충타임
		/*cout << "겨울보충타임" <<p<< endl;
		cout << newbie.size() << endl;
		cout << curyear.size() << endl;
		cout << nextyear.size() << endl;*/
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				map[i][j] += vitamin[i][j];

		curyear = nextyear;
	}

	cout <<newbie.size() +  curyear.size() << endl;
	return 0;
}