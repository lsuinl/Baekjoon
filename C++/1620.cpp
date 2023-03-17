#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    unordered_map<int, string> pocatmonnumber;
    unordered_map<string, int> pocatmonname;
    for (int i = 1; i <= n; i++)
    {
        string name;
        cin >> name;
        pocatmonnumber[i] = name;
        pocatmonname[name]=i;
    }
    for (int i = 0; i < m; i++)
    {
        string question;
        cin >> question;
        if (question[0] < 58)
        { // 키로찾기
            cout << pocatmonnumber[stoi(question)] << "\n";
        }
        else
        { // 값으로찾기
            cout<<pocatmonname[question]<<"\n";
        }
    }
}