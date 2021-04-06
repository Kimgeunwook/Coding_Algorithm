#include <iostream>
#include <vector>
using namespace std;
int arr[100000], N;
vector<int> v;
void init()
{
	v.clear();
}
void input()
{
	for (int i = 0; i < N; i++) cin >> arr[i];
}
void get_longest()
{
	v.push_back(arr[0]);
	for (int i = 1; i < N; i++)
	{
		if (arr[i] > v[v.size() - 1])
		{
			v.push_back(arr[i]);
		}
		else
		{
			int it = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[it] = arr[i];
		}
	}
}
int get_answer()
{
	return v.size();
}
int main()
{
	while (cin >> N)
	{
		init();
		input();
		get_longest();
		cout << get_answer() << endl;
	}
	return 0;
}
