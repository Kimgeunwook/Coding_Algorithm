//1433Ω√¿€
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct location {
	int x, y;
};
int M, N, L;
vector<int> v;
queue<location> animalq;
void Input()
{
	cin >> M >> N >> L;
	int a,b;
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		location newbie = { a,b };
		animalq.push(newbie);
	}
}

int bfs()
{
	int ans = 0;
	while (!animalq.empty())
	{
		location cur = animalq.front();
		animalq.pop();

		int s = 0, e = v.size() - 1;
		int _min = 1000000000;
		while (s <= e)
		{
			int mid = (s + e) / 2;
			if (v[mid] < cur.x)
			{
				s = mid + 1;
				_min = min(_min, cur.x - v[mid]);
			}
			else
			{
				e = mid - 1;
				_min = min(_min, v[mid] - cur.x);
			}
		}
		if (cur.y + _min <= L)ans++;
	}
	return ans;
}
int main()
{
	Input();
	cout << bfs() << endl;
	return 0;
}