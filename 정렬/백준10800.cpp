#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct info {
	int idx, color, size;
};
bool comp(info a, info b)
{
	return a.size < b.size; // 사이즈별 오름차순
}
vector<info> v;
int N;
int ans[200000], colorsum[200001];
void Input()
{
	scanf("%d", &N);
	//cin >> N;
	int a, b;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		//cin >> a >> b;
		info temp = {i, a, b};
		v.push_back(temp);
	}
}
int main()
{
	Input();
	sort(v.begin(), v.end(), comp);

	int sum = 0;
	for (int i = 0, j = 0; i < N; i++)
	{
		while (v[j].size < v[i].size)
		{
			sum += v[j].size;
			colorsum[v[j].color] += v[j].size;
			j++;
		}
		ans[v[i].idx] = sum - colorsum[v[i].color];
	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << "\n";
	return 0;
}