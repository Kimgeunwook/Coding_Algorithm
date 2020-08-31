//1506
#include <iostream>
using namespace std;
int N,k;
int arr[100001];
bool visit[100001], check[100001];
int ans = 0;
void dfs(int n)
{
	visit[n] = true;
	int next = arr[n];

	if (!visit[next])
		dfs(next);
	else if (!check[next])
	{
		for (int i = next; i != n; i = arr[i]) ans++;
		ans++;
	}
	check[n] = true;
}
int main()
{
	
	cin >> N;
	while (N--)
	{
		for (int i = 1; i <= 100000; i++)
		{
			visit[i] = false;
			check[i] = false;
		}
		ans = 0;
		cin >> k;
		
		for (int i = 1; i <= k; i++)
			cin >> arr[i];
		
		for (int i = 1; i <= k; i++)
			if(!visit[i]) dfs(i);

		cout << k - ans << endl;
	}
	return 0;
}