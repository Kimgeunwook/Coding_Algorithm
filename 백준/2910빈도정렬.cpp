#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;
int num, limit_num, n, flag = 0;
bool sortbycnt(const tuple<int, int, int> & a, const tuple<int, int, int> & b)
{
	if (get<2>(a) == get<2>(b))
	{
		return get<1>(a) < get<1>(b);
	}
	else
	{
		return get<2>(a) > get<2>(b);
	}
}
int main()
{
	vector<tuple<int, int, int>> v;
	//��������, ���°�� ����� ,ī��Ʈ
	cin >> num >> limit_num;
	cin >> n;
	v.push_back(make_tuple(n, 0, 1)); //�ع��������� ���Ϳ��� �ȳ����� �Ѱ��� �־��ֱ�
	for (int i = 1; i < num; i++)
	{
		flag = 0;
		cin >> n;
		for (int j = 0; j < v.size(); j++)
		{
			if (n == get<0>(v[j])) //�̹� �ִ� ���ڸ�
			{
				get<2>(v[j])++;
				flag = 1;
				break;
			}
		}
		if (flag == 0) //ó�� ���� ���ڸ�
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
