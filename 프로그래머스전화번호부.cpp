#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <map>
map<string, bool> m;

bool solution(vector<string> phone_book) {
	for (int i = 0; i < phone_book.size(); i++)	m.insert(make_pair(phone_book[i], true));
	
	for (int i = 0; i < phone_book.size(); i++)
		for (int j = 0; j < phone_book[i].length() - 1; j++)
			if (m[phone_book[i].substr(0, j + 1)]) return false;
		
	return true;
}
int main()
{
	cout << solution({"123", "456", "789"}) << endl;
	return 0;
}