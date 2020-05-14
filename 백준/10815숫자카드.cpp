#include <iostream>
using namespace std;
#include <algorithm>
int sang_geun[500001];
int arr[500001];
int main()
{
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> sang_geun[i];
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> arr[i];

	sort(sang_geun + 1, sang_geun + n + 1);

	for (int i = 1; i <= m; i++)
	{
		if (binary_search(sang_geun + 1, sang_geun + n + 1, arr[i]))
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
	return 0;
}