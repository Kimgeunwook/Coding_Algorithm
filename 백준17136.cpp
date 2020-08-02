//17:23시작
#include <iostream>
using namespace std;
#include <algorithm>
int map[11][11], temp[11][11];
int rest[6];
int _min = 987654321;
void detach(int x, int y, int size)
{
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			temp[i][j] = map[i][j];
	rest[size]++;
}
void attach(int x, int y, int size)
{
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			temp[i][j] = 0;
		
	rest[size]--;
}

bool measure(int x, int y, int size)
{
	int flag = 0;
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			if (temp[i][j] == 0) flag = 1;
	if (flag == 0 && rest[size] > 0) return true;
	else return false;			
} 

void dfs(int x, int y,int cnt)
{
	for(int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			if (temp[i][j] == 0 || cnt >= _min) continue;
			else //조건 + 재귀
			{
				for(int  a = 5; a >= 1; a-- )
				{
					if (measure(i, j, a)) { //a사이즈 붙일 수 있으면
						attach(i, j, a); // 붙이고
						dfs(i, j, cnt + 1); //다음단계 고고
						detach(i, j, a); //떼기
					}
				}
				return;
			}
		}
	// 종료조건
	int flag = 0;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			if (temp[i][j] == 1) flag = 1;
	if (flag == 0) {
		_min = min(_min, cnt);
	} 
}
int main()
{
	for (int i = 1; i <= 5; i++) rest[i] = 5;

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			cin >> map[i][j]; //원본맵
			temp[i][j] = map[i][j]; // 뗐다 붙였다 할 맵
		}

	dfs(1, 1, 0); // 1,1 에서 0개 붙인 것으로 시작
	if (_min == 987654321) cout << -1 << endl;
	else cout << _min << endl;
	
	return 0;
}