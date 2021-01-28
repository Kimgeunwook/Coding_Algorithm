#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct shark {
	int a, b, c;
};
bool cmp(shark a, shark b)
{
	return a.a < b.a;
}

int main()
{
	vector<shark> ff;
	ff.push_back({ 1,1,1 });
	ff.push_back({ 2,2,2 });
	sort(ff.begin(), ff.end(), cmp);
	return 0;
}