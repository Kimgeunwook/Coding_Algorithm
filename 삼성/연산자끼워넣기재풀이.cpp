#include <iostream>
#include <vector>
using namespace std;
int N, arr[11];
char temp[10];
int visit[10];
vector<char> op;
int _max = -999999999, _min = 987654321;
void dfs(int cnt)
{
	if (cnt == N - 1)
	{
		int sum = arr[0];
		for (int i = 0; i < N - 1; i++)
		{
			if (temp[i] == '+')
				sum += arr[i + 1];
			else if (temp[i] == '-')
				sum -= arr[i + 1];
			else if (temp[i] == '*')
				sum *= arr[i + 1];
			else if (temp[i] == '/')
				sum /= arr[i + 1];
		}
		if (sum > _max) _max = sum;
		if (sum < _min) _min = sum;
	}
	else
	{
		for (int i = 0; i < op.size(); i++)
		{
			if (visit[i] == 0)
			{
				visit[i] = 1;
				temp[cnt] = op[i];
			}
			else
				continue;
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int plus, minus, multiply, divide;
	cin >> plus >> minus >> multiply >> divide;
	for (int i = 0; i < plus; i++)
		op.push_back('+');
	for (int i = 0; i < minus; i++)
		op.push_back('-');
	for (int i = 0; i < multiply; i++)
		op.push_back('*');
	for (int i = 0; i < divide; i++)
		op.push_back('/');

	
	dfs(0);

	cout << _max << endl;
	cout << _min << endl;
	return 0;

}
