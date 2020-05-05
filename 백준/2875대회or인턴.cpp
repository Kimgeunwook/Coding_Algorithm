#include <iostream>
using namespace std;
int main() {
	int w, m, k;
	cin >> w >> m >> k;
	int max = 0;
	for (int i = 0; i <= k; i++)
	{
		if ((w - (k - i)) > (2 * (m - i)))
		{
			if (m - i>max)
				max = m - i;
		}

		else
		{
			if (((w - (k - i)) / 2)>max)
				max = (w - (k - i)) / 2;
		}

	}
	cout << max;
	return 0;
}