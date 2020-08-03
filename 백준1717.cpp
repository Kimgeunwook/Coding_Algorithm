#include <iostream>
#include <stdio.h>
using namespace std;
int n, m;
int parent[1000001];
int _find(int n)
{
	if (parent[n] == n) return n;
	else return parent[n] = _find(parent[n]);
}

void _Union(int a, int b)
{
	int i = _find(a);
	int j = _find(b);
	parent[i] = j;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	//scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	int a, b, c;
	for (int i = 0; i < m; i++) 
	{
		//scanf("%d %d %d", &a, &b, &c);
		cin >> a >> b >> c;
		if (a == 1) 
		{
			if (_find(b) == _find(c))
				cout << "YES" << "\n";
			//printf("YES\n");
			//puts("YES");

			else
				cout << "NO" << "\n";
				//printf("NO\n");
				//puts("NO");
				
		} 
		else _Union(b, c);
	}

	return 0;
}