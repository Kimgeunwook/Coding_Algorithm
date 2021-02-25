//08:00시작
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v, positive_v, negative_v, zero_v;
bool comp(int a, int b)
{
	return abs(a) > abs(b); // 사이즈별 오름차순
}

void input()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		v.push_back(a);
	}
}
void sorting()
{
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > 0) positive_v.push_back(v[i]);
		else if (v[i] < 0) negative_v.push_back(v[i]);
		else zero_v.push_back(0);
	}
}
int solve()
{
	int sum = 0;
	for (int i = 0; i < positive_v.size(); i += 2)
	{
		if (i == positive_v.size() - 1)
		{
			sum += positive_v[i];
			break;
		}
		sum += max(positive_v[i] * positive_v[i + 1], positive_v[i] + positive_v[i + 1]);
	}
	for (int i = 0; i < negative_v.size(); i += 2)
	{
		if (i == negative_v.size() - 1)
		{
			if (zero_v.size() == 0) sum += negative_v[i];
			break;
		}
		sum += negative_v[i] * negative_v[i + 1];
	}
	return sum;
}
int main()
{
	input();
	sorting();
	int answer = solve();
	cout << answer << endl;
}