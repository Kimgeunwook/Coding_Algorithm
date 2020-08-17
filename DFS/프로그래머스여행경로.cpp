#include <iostream>
#include <string>
#include <vector>
using namespace std;

string min_path = "a";
bool _visit[10000];
void dfs( vector<vector<string>> _tickets ,string cur, string path, int depth)
{
    if (depth == _tickets.size())
    {
        if (path < min_path)
        {
            min_path = path;
        }
        return;
    }

    for (int i = 0; i < _tickets.size(); i++)
    {
        if (_visit[i] == false && cur == _tickets[i][0])
        {
            _visit[i] = true;
            dfs( _tickets, _tickets[i][1] ,path + _tickets[i][1], depth + 1);
            _visit[i] = false;
        }
        
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visit(tickets.size(),false);

    
    dfs(tickets, "ICN", "ICN", 0);
    for (int i = 0; i < min_path.size(); i += 3)
    {
        answer.push_back(min_path.substr(i, 3));
    }
    //answer¿¡ ¼¼°³¾¿ Ãß°¡ÇÏ±â
    return answer;
}
