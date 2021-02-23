//1.���� ������ 10�̴ϱ� make_fill�Լ� ����Ͽ� ���� ������
//2. make_fill�Լ��� ������� ������ ���� ����� ���������� ���ð���� �ٸ��� �ȵ�
//3.�ֳ�? ���÷� (123, 1235) ���̽��� (123,124)���̽� �غ��� �ٽ� ���ذ� �� ���̴�.
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