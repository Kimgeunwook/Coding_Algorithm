#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct info {
	int x, y, idx;
};
bool comp(info a, info b)
{
	if (a.y != b.y)
		return a.y > b.y;
	else
		return a.x < b.x;
}
map<int, int> mL;
map<int, int> mR;
vector<info> v;
vector<vector<int>> answer;
vector<int> v_dfs;
vector<int> v_backtracking;

void make(int idx, int n)
{
	if (v[n].x < v[idx].x)
	{
		if (mL[idx] == 0)
		{
			mL[idx] = n;
		}
		else
		{
			make(mL[idx], n);
		}

	}
	else
	{
		if (mR[idx] == 0)
		{
			mR[idx] = n;
		}
		else
		{
			make(mR[idx], n);
		}

	}
}

void dfs(int n)
{
	v_dfs.push_back(v[n].idx);
	if (mL[n] != 0)
	{
		dfs(mL[n]);
	}
	if (mR[n] != 0)
	{
		dfs(mR[n]);
	}
}

void backtracking(int n)
{
	if (mL[n] != 0) backtracking(mL[n]);
	if (mR[n] != 0) backtracking(mR[n]);
	v_backtracking.push_back(v[n].idx);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	for (int i = 0; i < nodeinfo.size(); i++)
	{
		info newbie = { nodeinfo[i][0], nodeinfo[i][1], i + 1 };
		v.push_back(newbie);
	}
	sort(v.begin(), v.end(), comp);

	if (v.size() > 1)
	{
		for (int i = 1; i < v.size(); i++)
		{
			make(0, i); //배열, 시작점, 현재idx
		}
		dfs(0);
		backtracking(0);
	}
	else
	{
		v_dfs.push_back(1);
		v_backtracking.push_back(1);
	}


	answer.push_back(v_dfs);
	answer.push_back(v_backtracking);
	return answer;
}