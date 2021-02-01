//2151시작
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int K, sum;
int map[5][8];
queue<pair<int, int>> q; 
bool flag[4];
void show()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j <= 7; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
		
}
void input()
{
	cin >> K;
	for (int i = 1; i <= 4; i++)
		for (int j = 0; j < 8; j++)
			cin >> map[i][j];

	int a, b;
	for (int i = 0; i < K; i++)
	{
		cin >> a >> b;
		q.push({ a,b });
	}
	sum = 0;
	for (int i = 0; i <= 3; i++) flag[i] = false;
}
void rotation(int num, int dir)
{
	//1이시계 -1이반시계
	if (dir == 1)
	{
		int temp = map[num][7];
		for (int i = 7; i >= 1; i--)
			map[num][i] = map[num][i - 1];

		map[num][0] = temp;
	}
	else
	{
		int temp = map[num][0];
		for (int i = 0; i < 7; i++)
			map[num][i] = map[num][i + 1];

		map[num][7] = temp;
	}

}
void getflag()
{
	for (int i = 1; i <= 3; i++)
	{
		if (map[i][2] != map[i + 1][6]) flag[i] = true;
	}
}
void goleft(int num, int dir)
{
	//cout << "golefet" << num << " "<<dir << endl;
	if (num == 0) return;
	if (flag[num])
	{
		rotation(num , dir);
		goleft(num - 1 , -1*dir);
	}
}
void goright(int num, int dir)
{
	if (num == 5) return;
	if (flag[num - 1])
	{
		rotation(num , dir);
		goright(num + 1, -1*dir);
	}
}
void solve()
{
	while(!q.empty())
	{
		//show();
		int num = q.front().first;
		int dir = q.front().second;
		for (int i = 0; i <= 3; i++) flag[i] = false;
		getflag();
		rotation(num, dir);
		goleft(num -1, -1*dir);
		goright(num + 1, -1*dir);
		q.pop();
		/*for (int i = 1; i <= 3; i++)
			cout << flag[i] << " ";
		cout << endl;
		cout <<num<<","<<dir<< "결과" << endl;
		show();
		cout << endl;*/
	}
}
void getAnswer()
{
	for (int i = 1; i <= 4; i++)
		sum += pow(2, i - 1)*map[i][0];
}
int main()
{
	int T; cin >> T;
	for (int i = 1; i <= T; i++)
	{
		input();
		solve();
		getAnswer();
		cout << "#" << i << " " << sum << endl;
	}
	return 0;
}