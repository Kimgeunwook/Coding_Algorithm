#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, _max = -987654321;
string str;
vector<char> op;
vector<int> num;
int calc(char op, int front, int back)
{
	if (op == '+')
	{
		return front + back;
	}
	if (op == '-')
	{
		return front - back;
	}
	if (op == '*')
	{
		return front * back;
	}
}
void dfs(int _cnt,int result)
{
	if (_cnt >= op.size())
	{
		if (result > _max) _max = result;
		return;
	}
	dfs(_cnt + 1, calc(op[_cnt], result, num[_cnt+1]));
	if (op.size() - _cnt > 1)
	{
		long long result2 = calc(op[_cnt + 1], num[_cnt + 1], num[_cnt + 2]);
		dfs(_cnt + 2, calc(op[_cnt], result, result2));
	}
}
int main()
{
	cin >> N >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*')
			op.push_back(str[i]);
		else
			num.push_back(str[i]-'0');
	}
	dfs(0,num[0]);
	cout << _max << endl;
	return 0;
}
