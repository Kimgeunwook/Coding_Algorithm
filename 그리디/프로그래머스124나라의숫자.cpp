#include <string>
#include <vector>

using namespace std;
string arr[3] = { "4","1","2" };
string solution(int n) {
	string answer = "";
	while (n)
	{
		int divide = n / 3;
		int temp = n % 3;
		answer = arr[temp] + answer;
		n = divide;
		if (temp == 0) n--;
	}
	return answer;
}