#include <iostream>
using namespace std;
#include <vector>;
vector<int> v;
int temp[5];
int visit[5];
void dfs(int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < 5; i++)
			cout << temp[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			if (visit[i] == 1) continue;
			visit[i] = 1;
			temp[cnt] = v[i];
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}
int main()
{
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	dfs(0);
	return 0;
}
