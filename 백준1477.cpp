//2005Ω√¿€
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int N, M, L, answer;

void input() 
{
	cin >> N >> M >> L;
	for (int i = 0; i < N; i++)
	{
		int a; cin >> a;
		v.push_back(a);
	}
	v.push_back(0);
	v.push_back(L);
}

bool isok(int mid)
{
	int life = M;
	int cur = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] - cur > mid)
		{
			while (v[i] - cur > mid)
			{
				cur += mid;
				life--;
			}
		}
		cur = v[i];
		if (life < 0) return false;
	}
	return true;
}

void solve()
{
	int start = 0, end = L;
	while (start < end)
	{
		int mid = (start + end) / 2;

		if (isok(mid))
		{
			answer = mid;
			end = mid;
		}
		else
		{
			start = mid + 1;
		}
	}
}

int main()
{
	input();
	sort(v.begin(), v.end());
	solve();
	cout << answer << endl;
	return 0;
}