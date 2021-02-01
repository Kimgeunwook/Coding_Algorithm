//2119Ω√¿€
#include <iostream>
#include <cmath>
using namespace std;
int N, R, C;
int main()
{
	cout << (1 << 3) << endl;
	/*int ans = 0;
	cin >> N >> R >> C;
	while(N)
	{
		int HALF = pow(2, N) / 2;
		if (R < HALF && C >= HALF)
		{
			ans += pow(HALF, 2);
			C -= HALF;
		}
		else if (R >= HALF && C < HALF)
		{
			ans += 2 * pow(HALF, 2);
			R -= HALF;
		}
		else if (R >= HALF && C >= HALF)
		{
			ans += 3 * pow(HALF, 2);
			R -= HALF;
			C -= HALF;
		}
		N -= 1;
	}
	cout << ans << endl;*/
	return 0;
}