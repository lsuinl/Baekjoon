//시간초과,,가 밉다
// #include <iostream>

// using namespace std;

// int n;
// pair<int, int> linkeed[100000];
// bool visited[100000] = {
//     false,
// };

// void DFS(int goal, int now)
// {
//     for (int i = 0; i < n-1; i++)
//     {
//         if (linkeed[i].first == now && visited[linkeed[i].second] == false)
//         {
//             if (goal == linkeed[i].second)
//             {
//                 cout<<now<<'\n';
//                 return;
//             }
//             else
//             {
//                 visited[linkeed[i].second]=true;
//                 DFS(goal, linkeed[i].second);
//                 visited[linkeed[i].second]=false;
//             }
//         }
//         else if (linkeed[i].second == now && visited[linkeed[i].first] == false)
//         {
//             if (goal == linkeed[i].first)
//             {
//                 cout<<now<<'\n';
//                 return;
//             }
//             else
//             {
//                 visited[linkeed[i].first]=true;
//                 DFS(goal, linkeed[i].first);
//                 visited[linkeed[i].first]=false;
//             }
//         }
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n;
//     for (int i = 0; i < n - 1; i++)
//     {
//         cin >> linkeed[i].first >> linkeed[i].second;
//     }

//     visited[1]=true;
//     for (int i = 2; i <= n; i++)
//     {
//         DFS(i,1);
//     }
//     return 0;
// }

//다른서 구해온 것
#include <iostream>
#include <vector>

using namespace std;
#define MAX 100001

int N;
int arr[MAX];
bool visited[MAX];
vector<int> v[MAX];

void dfs(int k) {
    visited[k]=true;
    for(int i=0;i<v[k].size();i++) {
        int next = v[k][i];
        if(!visited[next]) {
            arr[next]=k;
            dfs(next);
        }
    }
}

int main() {
    cin >> N;

    for(int i=0;i<N;i++) {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    for(int i=2;i<=N;i++) cout << arr[i] << "\n";
}