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
			arr[second] = third; //이렇게 받는순간 한쪽점수로 소팅한거다
		}

		for (int i = 1; i <= first; i++)
		{
			if (i == 1)  //소팅한거에서 1등은 무조건 다른거보다 앞서므로 count++
			{
				count++;
				continue;
			}
			//if (a - arr[i] < i-1) //(그려보면서 이해할것!) a-arr[i]<i-1이면 자신보다 위에애들이 밑에갈 공간조차없는거여서 패스
			//	continue;
			//else
			//{
			flag = 0;
			for (int j = 1; j < i; j++) //자신보다 위에애들중 다른점수도 위에있으면 flag=1로줘서 count++못하게 막는다
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
