#include <iostream>
using namespace std;
int arr[100001];
int main()
{
	int num;
	cin >> num;
	while (num--)
	{
		int first, second, third, flag;
		int count = 0;
		cin >> first;
		for (int i = 1; i <= first; i++)
		{
			cin >> second >> third;
			arr[second] = third; //�̷��� �޴¼��� ���������� �����ѰŴ�
		}

		for (int i = 1; i <= first; i++)
		{
			if (i == 1)  //�����Ѱſ��� 1���� ������ �ٸ��ź��� �ռ��Ƿ� count++
			{
				count++;
				continue;
			}
			//if (a - arr[i] < i-1) //(�׷����鼭 �����Ұ�!) a-arr[i]<i-1�̸� �ڽź��� �����ֵ��� �ؿ��� �����������°ſ��� �н�
			//	continue;
			//else
			//{
			flag = 0;
			for (int j = 1; j < i; j++) //�ڽź��� �����ֵ��� �ٸ������� ���������� flag=1���༭ count++���ϰ� ���´�
			{
				if (arr[j] < arr[i])
				{
					flag = 1;
					break;
				}
			}
			//	}
			if (flag == 0)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}