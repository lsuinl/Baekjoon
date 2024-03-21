#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> getlongnum(int n) {
    vector<int> tmp;
    tmp.push_back(1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < tmp.size(); j++) {
            tmp[j] *= 2;
        }
        for (int j = 0; j < tmp.size(); j++) {
            if (tmp[j] >= 10) {
                if(j + 1 == tmp.size()) tmp.push_back(tmp[j] / 10);
                else {
                    tmp[j + 1] += tmp[j] / 10;
                }
            }
            tmp[j] %= 10;
        }
    }
    return tmp;
}

void replay(int n, int from, int to, int by) {
    if (n == 1) {
        cout << from << " " << to << "\n";
        return;
    }
    replay(n - 1, from, by, to);
    cout << from << " " << to << "\n";
    replay(n - 1, by, to, from);
}

int main() {
    unsigned long long n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    vector<int> count = getlongnum(n);
    count[0] -= 1;
    for (int i = count.size() - 1; i >= 0; i--) {
        cout << count[i];
    }
    cout << "\n";
    if (n <= 20) replay(n, 1, 3, 2);
    return 0;
}
