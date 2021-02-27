#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool visit[32]; //true°¡ ¾È°¡Á®¿Â¾Öµé
bool visit_res[32];
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();
	for (int i = 0; i < lost.size(); i++) visit[lost[i]] = true;
	for (int i = 0; i < reserve.size(); i++) visit_res[reserve[i]] = true;
	
	
	for (int i = 0; i < reserve.size(); i++)
	{
		if (visit[reserve[i]] == true)
		{
			visit[reserve[i]] = false;
			answer++;
			continue;
		}
		if (visit[reserve[i] - 1] == true &&visit_res[reserve[i] - 1] == false )
		{
			visit[reserve[i] - 1] = false;
			answer++;
			continue;
		}
		if (visit[reserve[i] + 1] == true && visit_res[reserve[i] + 1] == false)
		{
			visit[reserve[i] + 1] = false;
			answer++;
			continue;
		}
		
	}
	return answer;
}
int main()
{
	cout << solution(5, {2,3,4 }, {3, 4,5 }) << endl;
	return 0;
}
