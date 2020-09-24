//1313Ω√¿€
#include <vector>
bool visit[201];
using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	for (int i = 0; i < numbers.size() - 1; i++)
		for (int j = i + 1; j < numbers.size(); j++)
			if (!visit[numbers[i] + numbers[j]]) visit[numbers[i] + numbers[j]] = true;

	for (int i = 0; i <= 200; i++)
		if (visit[i]) answer.push_back(i);

	return answer;
}