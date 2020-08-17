#include <iostream>
using namespace std;

int arr[100000];
int sum = 0;
int _l, _r;
int _min = 987654321;
int N, S;
int main() 
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sum = arr[0];
	while (_l <= _r && _r < N)
	{

		//조건에 만족하면(==합이 S이상이면)
		if (sum >= S)
		{
			//최소값이랑 비교
			if (_r - _l + 1 < _min) _min = _r - _l + 1;

			 
			//왼쪽꺼++
			sum -= arr[_l];
			_l++;
		}
		else
		{
			//오른쪽꺼++
			_r++;
			sum += arr[_r];
		}
	}
	if (_min == 987654321) {
		cout << 0 << endl;
	}
	else
	{
		cout << _min << endl;
	}
	
	return 0;
}
