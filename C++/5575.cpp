#include <iostream>
#include <math.h>
using namespace std;
// https://hyanghope.tistory.com/312
int main() {
    int h[3], m[3], s[3], hout,mout,sout;

    for (int i = 0; i < 3; i++) {
        cin >> h[i] >> m[i] >> s[i];
        cin >> hout >> mout >> sout;
        h[i] = hout - h[i];
        m[i] = mout - m[i];
        s[i] = sout - s[i];
        if (s[i] < 0) {
            s[i] += 60;
            m[i]--;
        }
        if (m[i] < 0) {
            m[i] += 60;
            h[i]--;
        }

    }

    for (int i = 0; i < 3; i++) {
        cout << h[i]<<" " << m[i]<< " " << s[i]<<endl;
    }

    return 0;
}