#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//struct Node {
//	int point_cnt; //몇번 거쳐간지
//	struct Node* next; //다음 노드
//	int remain_cnt; //남은글자 카운트
//	string data;
//
//};
bool compare(string a, string b)
{
	if (a.size() < b.size()) return true;
	else if (a.size() == b.size())
		if (a < b) return true;
	return false;
}
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	vector<string> rwords = words;
	for (int i = 0; i < rwords.size(); i++) reverse(rwords[i].begin(), rwords[i].end());

	sort(rwords.begin(), rwords.end(), compare);
	sort(words.begin(), words.end(), compare);

	int start;
	int end;
	for (int i = 0; i < queries.size(); i++)
	{
		string a_cnt = "";
		string z_cnt = "";
		string original = "";
		if (queries[i][0] == '?') //리버스
		{
			for (int j = queries[i].size()-1; j >= 0; j--)
			{
				if (queries[i][j] == '?')
				{
					a_cnt.append("a");
					z_cnt.append("z");
				}
				else original += queries[i][j];
			}
			start = lower_bound(rwords.begin(), rwords.end(), original + a_cnt, compare) - rwords.begin();
			end = upper_bound(rwords.begin(), rwords.end(), original + z_cnt, compare) - rwords.begin();
		}
		else { //정주행
			for (int j = 0; j < queries[i].size(); j++)
			{
				if (queries[i][j] == '?')
				{
					a_cnt.append("a");
					z_cnt.append("z");
				}
				else original += queries[i][j];
			}
			start = lower_bound(words.begin(), words.end(), original+a_cnt, compare) - words.begin();
			end = upper_bound(words.begin(), words.end(), original + z_cnt, compare) - words.begin();
		}
		answer.push_back(end - start);
	}
	
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return answer;
}
int main()
{
	vector<string> answer2 = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	solution(answer2, { "fro??", "????o", "fr???", "fro???", "pro?" });
	
	return 0;
}
