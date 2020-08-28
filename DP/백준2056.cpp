//13:11Ω√¿€
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>
vector<int> v[10001];
int _max[10001];
int _min[10001];
int spend[10001];
int N;
void Input()
{
	cin >> N;
	int a;
	for (int i = 1; i <= N; i++)
	{
		cin >> spend[i];
		_max[i] = spend[i];
		cin >> a;
		int b;
		for (int j = 0; j < a; j++)
		{
			cin >> b;
			v[b].push_back(i);
		}
	}
}
void dp()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
			_max[v[i][j]] = max(_max[v[i][j]], _max[i] + spend[v[i][j]]);
	}
		
}
int main()
{
	Input();
	dp();
	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = max(ans, _max[i]);
	
	cout << ans << endl;
	return 0;
}