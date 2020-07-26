//19:50Ω√¿€
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
set<char> _s;
string s[10], answer[10];
vector<char> v;
int N;
int arr[10];
int visit[10];
int temp[10];
int _max = -1;
map<char, int> m;
void dfs(int cnt)
{
	if (cnt == v.size())
	{
		
		for (int i = 0; i < v.size(); i++)
			m[v[i]] = temp[i];

		for (int i = 0; i < N; i++)
			answer[i] = "";

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < s[i].length(); j++)
			{
				//cout << char(s[i][j]) <<":"<< m[char(s[i][j])] <<" ";
				answer[i] += to_string(m[char(s[i][j])]);
			}
		}
		/*for (int i = 0; i < N; i++)
			cout << answer[i] << " ";
		cout << endl;*/
		int totalsum = 0;
		for (int i = 0; i < N; i++)
		{
			totalsum += stoi(answer[i]);
		}
		_max = max(_max, totalsum);
	}
	else
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (visit[i] == 1)continue;
			visit[i] = 1;
			temp[cnt] = arr[i];
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}
int main()
{

	cin >> N;
	for (int i = 0; i < 10; i++)
		arr[i] = 9 - i;

	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
		for (int j = 0; j < s[i].length(); j++)
		{
			_s.insert(s[i][j]);
		}	
	}
	set<char>::iterator it;
	for (it = _s.begin(); it != _s.end(); it++)
	{
		v.push_back(*it);
	}

	dfs(0);
	cout << _max << endl;
	return 0;
}