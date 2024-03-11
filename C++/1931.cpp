#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, result, count = 1;

    cin >> n;
    vector<pair<int, int>> time;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        time.push_back(pair<int, int>(end, start));
    }
    sort(time.begin(), time.end());

    int compare = time[0].first;
    for (int i = 1; i < n; i++)
    {
        if (compare <= time[i].second)
        {
            count++;
            compare = time[i].first;
        }
    }

    cout << count;

    return 0;
}
