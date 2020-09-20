#include <iostream>
using namespace std;
#include <vector>;
int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(v.begin, 7);
	return 0;
}