//1502시작
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> vi;
vector<char> vc;
int N, _max = -987654321;
string s;
int SIZE;
void Input() {
	cin >> N;
	cin >> s;
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0) // 숫자
			vi.push_back(s[i] - '0');
		else
			vc.push_back(s[i]);
	}
	SIZE = vc.size();
}
int calc(int x, int y, char op)
{
	if ( op == '+') return x + y;
	else if(op == '-') return x - y;
	else if(op == '*') return x * y;
}
void dfs(int cnt, int result)
{
	if (cnt >= SIZE)
	{
		_max = max(_max, result);
	}
	else
	{
		// a + b + c 유형
		dfs(cnt + 1, calc(result, vi[cnt + 1] , vc[cnt]));

		// a + (b + c)유형
		if (cnt + 2 <= SIZE)
		{
			int nextResult = calc(vi[cnt + 1], vi[cnt + 2], vc[cnt + 1]);
			int curResult = calc(result, nextResult, vc[cnt]);
			dfs(cnt + 2, curResult);
		}
	}
}
int main()
{
	Input();
	dfs(0, vi[0]); //cnt , sum
	cout << _max << endl;
	return 0;
}
		