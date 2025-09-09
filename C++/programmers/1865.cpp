#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>   // INT_MAX, INT_MIN


using namespace std;


int minCost[501] = { 0, };
vector<vector<pair<int, int>>> road;

bool find(int n) {
    queue<int> q;
    q.push(n);
    do {
        int start = q.front();
        q.pop();
        if (start == n && minCost[n] == INT_MAX)
            minCost[n] = 0;
        else if (start == n && minCost[n] < 0)
            break;
        else if (start == n)
            continue;

        for (int i = 0; i < road[start].size(); i++) {
            int end = road[start][i].first;
            int cost = road[start][i].second;
            if (minCost[end] > (long long)cost + minCost[start]) {
             // if (minCost[end] != INT_MAX && (cost + minCost[start]) - minCost[end] < 0) {
             //    cout << "출발지: " << start << endl;
             //    cout << minCost[start] << endl;
             //    cout << "위치: " << end << endl;
             //    cout << "총비용: " << (cost + minCost[start]) << endl;
             //    cout << "초기:" << minCost[end] << endl;
             //     return true;
             // }
                minCost[end] = cost + minCost[start];
                q.push(end);
            }
        }
    } while (!q.empty());
    return(minCost[n] < 0);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, w;
        int list[200];
        cin >> n >> m >> w;

        //초기화
        road.clear();
        road.resize(n + 1);
        fill(minCost, minCost + 501, INT_MAX);

        //도로 입력
        for (int j = 0; j < m; j++) {
            int s, e, t;
            cin >> s >> e >> t;
            road[s].push_back({ e,t });
            road[e].push_back({ s,t });
        }
        //웜홀 입력
        for (int j = 0; j < w; j++) {
            int s, e, t;
            cin >> s >> e >> t;
            road[s].push_back({ e,-t });
            list[j] = s;
        }
        //최소 거리 찾기
        bool isFind = false;
        for (int j = 0; j < w; j++) {
            if (find(list[j])) {
                isFind = true;
                break;
            }
        }
        string isCan = isFind ? "YES" : "NO";
        cout << isCan << "\n";
    }



    return 0;
}