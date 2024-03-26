#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    deque<int> de;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int num;
        cin >> name;
        if (name == "push_back" || name == "push_front")
            cin >> num;
        if (name == "push_back")
            de.push_back(num);
        else if (name == "push_front")
            de.push_front(num);
        else if (name == "pop_front") {
            if (de.empty() == 1)cout << -1 << '\n';
            else {
            cout << de.front() << '\n';
            de.pop_front();
            }
        }
        else if (name == "pop_back") {
            if (de.empty() == 1)cout << -1 << '\n';
            else {
                cout << de.back() << '\n';
                de.pop_back();
            }
        }
        else if (name == "size")
            cout << de.size() << '\n';
        else if (name == "empty")
            cout << de.empty() << '\n';
        else if (name == "front"){
        if (de.empty() == 1)cout << -1 << '\n';
        else cout << de.front() << '\n';
        }
        else if (name == "back"){
        if (de.empty() == 1)cout << -1 << '\n';
        else cout << de.back() << '\n';
        }
    }
    return 0;
}