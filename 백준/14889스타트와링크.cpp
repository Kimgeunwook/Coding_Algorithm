#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> start;
vector<int> link;
int map[30][30], num, mmin = 987654321;
void calc()
{
	for (int i = 1; i <= num; i++)					//start에 없는원소들 link에 넣어주기
		if (!binary_search(start.begin(), start.end(), i))
			link.push_back(i);

	int start_sum = 0, link_sum = 0;
	for (int i = 0; i<(num / 2) - 1; i++)
		for (int j = i + 1; j <= (num / 2) - 1; j++)
		{
			start_sum += map[start[i]][start[j]];
			link_sum += map[link[i]][link[j]];
		}

	if ((start_sum >= link_sum) && (start_sum - link_sum < mmin))
		mmin = start_sum - link_sum;
	else if ((start_sum < link_sum) && (link_sum - start_sum < mmin))
		mmin = link_sum - start_sum;

}

void dfs(int begin, int cnt)
{
	if (cnt == 1)
	{
		for (int i = begin; i <= num; i++)
		{
			start.push_back(i);
			calc();
			start.pop_back();
			link.clear();
		}
	}
	else
	{
		for (int i = begin; i <= (num - cnt + 1); i++)
		{
			start.push_back(i);
			dfs(i + 1, cnt - 1);
			start.pop_back();
		}
	}
}

int main() {
	cin >> num;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
		{
			cin >> map[i][j];
			map[i][j] += map[j][i];

			if (map[i][j] > map[j][i])
				map[j][i] = map[i][j];
		}
	start.push_back(1);
	dfs(2, (num / 2) - 1);//2부터 (num/2)-1개뽑아라
	cout << mmin;
	return 0;
}