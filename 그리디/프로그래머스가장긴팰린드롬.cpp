#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s = "abcdefg";
	
	cout << s.substr(3) << endl; //defg
	cout << s.substr(3, 2) << endl; //de
	cout << s.substr(3, 200) << endl; //defg
	cout << s.substr(100) << endl;
	return 0;
}