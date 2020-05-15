#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> v;
vector<char> op;
int _cnt = 1;
int main()
{
	int N, plus, minus, multiply, divide;
	int a;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	cin >> plus;
	for (int i = 0; i < plus; i++)
		op.push_back('+');
	
	cin >> minus;
	for (int i = 0; i < minus; i++)
		op.push_back('-');

	cin >> multiply;
	for (int i = 0; i < multiply; i++)
		op.push_back('*');

	cin >> divide;
	for (int i = 0; i < divide; i++)
		op.push_back('/');
	long long max = -1000000000, min = 1000000000;
	sort(op.begin(), op.end());
	do {
		long long cur = v[0];
		for (int i = 1; i < N; i++)
		{
			if (op[i - 1] == '+')
				cur += v[i];
			if (op[i - 1] == '-')
				cur -= v[i];
			if (op[i - 1] == '*')
				cur *= v[i];
			if (op[i - 1] == '/')
				cur = cur / v[i];
		}
		if (cur > max)
			max = cur;
		if (cur < min)
			min = cur;
	} while (next_permutation(op.begin(), op.end()));
	cout << max << endl;
	cout << min << endl;
	return 0;
}