#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    int n, m;
    vector<vector<int>> line;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        deque<int> check;
        for (int j = 0; j < line.size(); j++)
        {
            if (find(line[j].begin(), line[j].end(), a) != line[j].end())
            {
                line[j].push_back(b);
                check.push_back(j);
            }
            else if (find(line[j].begin(), line[j].end(), b) != line[j].end())
            {
                line[j].push_back(a);
                check.push_back(j);
            }
            if(check.size()==2){
                line[j].insert(line[j].begin(),line[*(check.end())].begin(),line[*(check.end())].end()); //결합
                line.erase(line.begin()+ *(check.end()));
                check.pop_back();
            }
        }
        if(check.size()==0)
            line.push_back({a, b});
    }
    cout<<line.size();
    return 0;
}