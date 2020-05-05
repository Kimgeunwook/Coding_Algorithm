#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;
int num, limit_num, n, flag = 0;
bool sortbycnt(const tuple<int, int, int> & a, const tuple<int, int, int> & b)
{
	if (get<2>(a) == get<2>(b)) //tuple 세번째 인자인 카운트 가 같을경우 
	{
		return get<1>(a) < get<1>(b);  //tuple 두번째 인자인 먼저 들어온 인자에게 우선순위를 준다
	}
	else
	{
		return get<2>(a) > get<2>(b); //tuple세번째 인자인 카운트로 정렬
	}
}
int main()
{
	vector<tuple<int, int, int>> v;
	//무슨숫자, 몇번째로 들온지 ,카운트
	cin >> num >> limit_num;
	cin >> n;
	v.push_back(make_tuple(n, 0, 1)); //밑밑포문에서 벡터오류 안나려면 한개는 넣어주기
	for (int i = 1; i < num; i++)
	{
		flag = 0;
		cin >> n;
		for (int j = 0; j < v.size(); j++)
		{
			if (n == get<0>(v[j])) //이미 있는 숫자면
			{
				get<2>(v[j])++; //카운트 늘려주고
				flag = 1;//플래그 지정
				break;
			}
		}
		if (flag == 0) //처음 나온 숫자면
		{
			v.push_back(make_tuple(n, v.size(), 1)); 
		}
	}
	sort(v.begin(), v.end(), sortbycnt);
	for (int i = 0; i < v.size(); i++)
		for (int j = 1; j <= get<2>(v[i]); j++)
			cout << get<0>(v[i]) << " ";
	return 0;
}
