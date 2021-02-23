//1.길이 제한이 10이니까 make_fill함수 사용하여 길이 맞춰줌
//2. make_fill함수로 만들어진 벡터의 소팅 결과와 원본벡터의 소팅결과가 다르면 안됨
//3.왜냐? 예시로 (123, 1235) 케이스랑 (123,124)케이스 해보면 다시 이해가 될 것이다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int T;
vector<pair<string,int>> v, v_fill;
void init()
{
	v.clear();
	v_fill.clear();
}
string make_fill(string s)
{
	string ret = s;
	while (ret.size() < 10) ret += "a";
	
	return ret;
}
void input()
{
	int N; cin >> N;
	string s;
	for(int i = 0 ; i <  N ; i++)
	{
		cin >> s;
		v.push_back({ s, i });
		v_fill.push_back({ make_fill(s), i});
	}
}
bool solve()
{
	sort(v.begin(), v.end());
	sort(v_fill.begin(), v_fill.end());

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second != v_fill[i].second) return false;
	}
	return true;
}
int main()
{
	cin >> T;
	while (T--)
	{
		init();
		input();
		if (solve()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}