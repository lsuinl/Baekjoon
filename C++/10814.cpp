#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string name[n];
    vector<pair<int, int>> suin;
    for (int i = 0; i < n; i++)
    {
        int age;
        cin >> age >> name[i];
        suin.push_back(pair<int, int>(age, i));
    }
    sort(suin.begin(), suin.end());
    for (int i = 0; i < n; i++)
    {
        int j = suin[i].second;
        cout << suin[i].first << " " << name[j] << '\n';
    }
    return 0;
}