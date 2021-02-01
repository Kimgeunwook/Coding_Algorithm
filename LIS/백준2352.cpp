#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int N, arr[40001];
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	v.push_back(arr[1]);
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] > v[v.size() - 1])
		{
			v.push_back(arr[i]);
			continue;
		}
		int it = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		v[it] = arr[i];
	}

	cout << v.size() << endl;
	return 0;
}