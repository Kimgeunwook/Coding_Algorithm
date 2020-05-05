#include <iostream>
using namespace std;
#include <queue>
class item
{
public:
	int num;
	int cnt;
	item(int _num, int _cnt)
	{
		num = _num;
		cnt = _cnt;
	}
};
queue<item> q;
bool is_visit[200001];
int start, finish;
int main()
{
	cin >> start >> finish;
	q.push(item(start, 0));
	is_visit[start] = true;

	if (start >= finish)
		cout << start - finish << endl;
	else
		while (1)
		{
			if (q.front().num + 1 == finish || q.front().num * 2 == finish || q.front().num - 1 == finish)
			{
				cout << q.front().cnt + 1 << endl;
				break;
			}
			else
			{
				if (is_visit[q.front().num + 1] == false)
				{
					q.push(item(q.front().num + 1, q.front().cnt + 1));
					is_visit[q.front().num + 1] = true;
				}
				if (q.front().num * 2<2 * finish - start + 1)
					if (is_visit[q.front().num * 2] == false)
					{
						q.push(item(q.front().num * 2, q.front().cnt + 1));
						is_visit[q.front().num * 2] = true;
					}

				if (q.front().num - 1>0)
					if (is_visit[q.front().num - 1] == false)
					{
						q.push(item(q.front().num - 1, q.front().cnt + 1));
						is_visit[q.front().num - 1] = true;
					}

				q.pop();
			}
		}

	return 0;
}
