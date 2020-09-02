//1616Ω√¿€
#include <string>
#include <vector>
using namespace std;

int idx = 0;
vector<int> solution(int n, int s) {
	vector<int> answer(n);
	if (n > s)
	{
		answer.clear();
		answer.push_back(-1);
	}
	else
	{
		int divide = s / n;
		int temp = s % n;
		for (int i = 0; i < n - temp; i++) answer[idx++] = divide;
		for (int i = n - temp; i < n; i++) answer[idx++] = divide + 1;
	}
	return answer;
}