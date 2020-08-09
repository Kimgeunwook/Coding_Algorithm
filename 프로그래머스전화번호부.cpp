//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//#include <map>
//map<string, bool> m;
//
//bool solution(vector<string> phone_book) {
//	for (int i = 0; i < phone_book.size(); i++)	m.insert(make_pair(phone_book[i], true));
//	
//	for (int i = 0; i < phone_book.size(); i++)
//		for (int j = 0; j < phone_book[i].length() - 1; j++)
//			if (m[phone_book[i].substr(0, j + 1)]) return false;
//		
//	return true;
//}
#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool answer;
class Node
{
public:
	Node * next[10];
	bool isnext;
	bool isfinish;

	Node()
	{
		isnext = false;
		isfinish = false;
		for (int i = 0; i < 10; ++i)
			next[i] = 0;
	}

	void insert(string tmp)
	{
		if (tmp.length() == 0)
		{
			isfinish = true;
			if (isfinish == isnext)
				answer = false;

			return;
		}
		int nextNum = tmp[0] - '0';

		if (next[nextNum] == 0)
		{
			next[nextNum] = new Node;
			isnext = true;
			if (isfinish == true)
				answer = false;
		}

		next[nextNum]->insert(tmp.substr(1, tmp.length() - 1));
	}
};

bool solution(vector<string> phoneBook) {
	answer = true;

	Node *root = new Node;
	for (int i = 0; i < phoneBook.size(); ++i)
	{
		string str = phoneBook[i];
		root->insert(str);
	}

	return answer;
}

int main()
{
	cout << solution({"123", "456", "789"}) << endl;
	return 0;
}