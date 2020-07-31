#include <iostream>
using namespace std;
int location = 0, n, length, D, R, G, seconds = 0;
int main()
{
	cin >> n >> length;
	for (int i = 0; i < n; i++)
	{
		cin >> D >> R >> G;
		seconds += D - location;
		location = D;
		if (seconds % (R + G) <= R)
		{
			seconds += R - (seconds % (R + G));
		}
	}
	seconds += length - D;
	cout << seconds << endl;
	return 0;
}
