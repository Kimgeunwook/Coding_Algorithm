#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
int N, M, K;
int map[10][10], vitamin[10][10]; // �ָ�   �Է¾�и�

struct tree
{
	int x;
	int y;
	int age;
};
struct compare {
	bool operator()(tree a, tree b)
	{
		return a.age > b.age;
	}
};
queue<tree> newbie, curyear, mother,dead, nextyear; //���� ���� ���� ����
priority_queue<tree, vector<tree>, compare> pqtree;

int main()
{
	cin >> N >> M >> K; //��ũ��   ��������   �����������

	for (int i = 0; i < N; i++) //ó�� ���� ���5�� �ʱ�ȭ
		for (int j = 0; j < N; j++)
			map[i][j] = 5;

	for (int i = 0; i < N; i++) //�ܿ���
		for (int j = 0; j < N; j++)
			cin >> vitamin[i][j];

	for (int i = 0; i < M; i++)//////////////���� ��ġ �Է¹ޱ�
	{
		int x, y, age;
		cin >> x >> y >> age;
		tree a = { x - 1,y - 1,age };
		pqtree.push(a);
	}

	//���� ť �����
	while (!pqtree.empty())
	{
		curyear.push(pqtree.top());
		pqtree.pop();
	} 
	
	for (int p = 0; p < K; p++)////////K���ݺ�
	{
		int curx, cury, curage;
		tree temp;

		//����� ������Ÿ��
		/*cout << "���񵹸�����"<<p << endl;
		cout << newbie.size() << endl;
		cout << curyear.size() << endl;
		cout << nextyear.size() << endl;*/
		while (!nextyear.empty())
		{
			nextyear.pop();
		}
		while (!dead.empty())
		{
			dead.pop();
		}
		while (!newbie.empty())
		{
			curx = newbie.front().x;
			cury = newbie.front().y;
			curage = newbie.front().age;
			///////////////////
			if (curage <= map[curx][cury]) //��� �������ִ�.
			{
				map[curx][cury] -= 1;
				curage += 1;
				temp = { curx,cury,curage };
				nextyear.push(temp);
			}
			else //��� ������ ����.
			{
				temp = { curx, cury, curage };
				dead.push(temp);
			}
			////////////////
			newbie.pop();
		}

		//���ؾֵ� ������
		/*cout << "���ؾֵ鵹������"<<p << endl;
		cout << newbie.size() << endl;
		cout << curyear.size() << endl;
		cout << nextyear.size() << endl;*/
		while (!mother.empty())
		{
			mother.pop();
		}
		while (!curyear.empty())
		{
			curx = curyear.front().x;
			cury = curyear.front().y;
			curage = curyear.front().age;
			if (curage <= map[curx][cury]) //��� �������ִ�.
			{
				map[curx][cury] -= curage;
				curage += 1;
				temp = {curx,cury,curage};
				if (curage % 5 == 0)
				{
					mother.push(temp);
				}
				nextyear.push(temp);
			}
			else //��� ������ ����.
			{
				temp = { curx, cury, curage};
				dead.push(temp);
			}
			curyear.pop();
		}

		//���ľ���Ÿ��
		/*cout << "���ĵ�������" <<p<< endl;
		cout << newbie.size() << endl;
		cout << curyear.size() << endl;
		cout << nextyear.size() << endl;*/
		while (!newbie.empty())
		{
			newbie.pop();
		}
		while (!mother.empty())
		{
			curx = mother.front().x;
			cury = mother.front().y;
			for (int a = -1; a < 2; a++)
				for (int b = -1; b < 2; b++)
					if (!(a == 0 && b == 0) && curx + a >= 0 && curx + a < N && cury + b >= 0 && cury + b < N)
					{
						tree add = { curx + a, cury + b,1 };
						newbie.push(add);
					}

			mother.pop();
		}

		//�����ֵ�->���Ÿ��
		/*cout << "�����ֵ� ��ȰŸ��"<<p << endl;
		cout << newbie.size() << endl;
		cout << curyear.size() << endl;
		cout << nextyear.size() << endl;*/
		while (!dead.empty())
		{
			curx = dead.front().x;
			cury = dead.front().y;
			curage = dead.front().age;
			map[curx][cury] += curage / 2;
			dead.pop();
		}

		//����Ÿ��
		/*cout << "�ܿﺸ��Ÿ��" <<p<< endl;
		cout << newbie.size() << endl;
		cout << curyear.size() << endl;
		cout << nextyear.size() << endl;*/
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				map[i][j] += vitamin[i][j];

		curyear = nextyear;
	}

	cout <<newbie.size() +  curyear.size() << endl;
	return 0;
}