//1540½ÃÀÛ
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
typedef pair<int, int> Pair;
map<Pair, bool> visitNode;
map< pair< Pair, Pair>, bool> visitDirect;
int solution(vector<int> arrows) {
	int answer = 0;
	int curX = 0, curY = 0;
	visitNode[{curX, curY}] = true;
	
	for (int i = 0; i < arrows.size(); i++)
	{
		for (int k = 0; k < 2; k++)
		{
			int nextX = curX + dx[arrows[i]];
			int nextY = curY + dy[arrows[i]];

			if (visitNode[{nextX, nextY}] == true)
			{
				if (visitDirect[{ {curX, curY}, { nextX, nextY } }] == false && visitDirect[{ {nextX, nextY}, { curX, curY }}] == false)
				{
					answer++;
				}
			}

			visitNode[{nextX, nextY}] = true;
			visitDirect[{ {curX, curY}, { nextX, nextY } }] = true;

			curX = nextX;
			curY = nextY;
		}
	}

	return answer;
}

int main()
{
	cout << solution({ 6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0 }) << endl;
	return 0;
}
