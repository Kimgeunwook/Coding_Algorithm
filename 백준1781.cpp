////정석 방법
////1.날짜순 오름차순 정렬
////2.라면 최소 힙에 넣으면서 날짜<최소 힙사이즈가 되면 한개 빼기
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <functional>
//using namespace std;
//int N, answer = 0;
//vector<pair<int, int>> v;
//priority_queue<int, vector<int>, greater<int>> pq;
//void input()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		int a, b; cin >> a >> b;
//		v.push_back({ a,b });
//	}
//}
//
//void solve()
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		int cur_dead = v[i].first;
//		int cur_noodle = v[i].second;
//		pq.push(cur_noodle);
//
//		if (cur_dead < pq.size())
//		{
//			pq.pop();
//		}
//	}
//}
//void get_answer()
//{
//	while (!pq.empty())
//	{
//		answer += pq.top();
//		pq.pop();
//	}
//}
//int main()
//{
//	input();
//	sort(v.begin(), v.end());
//	solve();
//	get_answer();
//	cout << answer << endl;
//	return 0;
//}

//유니온 파인드 방법
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[200001];
int N;
long long answer;
vector<pair<int, int>> v;
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
}
void init()
{
	for (int i = 0; i <= N; i++)
		parent[i] = i;
}
int _find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = _find(parent[x]);
}
void _union(int x, int y)
{
	x = _find(x);
	y = _find(y);
	parent[x] = y;
}

bool comp(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }
void solve()
{
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++)
	{
		int cur_dead = _find(v[i].first);
		int cur_noodle = v[i].second;

		if (cur_dead != 0)
		{
			answer += cur_noodle;
		}
		_union(cur_dead, cur_dead - 1);
	}
}
int main()
{
	input();
	init();
	solve();
	cout << answer << endl;
	return 0;
}