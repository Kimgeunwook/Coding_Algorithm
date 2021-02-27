#include <iostream>
#include <string>
using namespace std;
int stack[1000001];
string original;
string bomb;
char lastChar;
int idx = 0;
void solve()
{
	for (int i = 0; i < original.size(); i++)
	{
		stack[idx++] = original[i];
		if (original[i] == lastChar)
		{
			int flag = 0;
			for (int j = 0; j < bomb.size(); j++)
			{
				if (stack[idx - 1 - j] == bomb[bomb.size() - 1 - j] && i - j >= 0) continue;
				else flag = 1;
			}
			if (flag == 0)
			{
				idx -= bomb.size();
			}
		}
	}
}
int main()
{
	cin >> original;
	cin >> bomb;
	lastChar = bomb[bomb.size() - 1];

	
	solve();

	string ans = "";
	for (int i = 0; i < idx; i++)
		ans += stack[i];
	if (ans == "") cout << "FRULA" << endl;
	else cout << ans << endl;
}