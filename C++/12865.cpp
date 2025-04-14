#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> obj[101];  
int n, k;
int sum[101][100001];  

int dp() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j < obj[i - 1].second) {
                sum[i][j] = sum[i - 1][j];  
            } else {
                sum[i][j] = max(sum[i - 1][j], sum[i - 1][j - obj[i - 1].second] + obj[i - 1].first);
            }
        }
    }
    return sum[n][k];  
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> obj[i].second >> obj[i].first; 
    }

    cout << dp() << "\n";  
    return 0;
}
