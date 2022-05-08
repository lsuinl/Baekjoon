#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int n, x;
	string command;
	queue<int> suin;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "push") {
			cin >> x;
			suin.push(x);
		}
		else if (command == "pop")
			if (suin.empty())
				cout << -1 << endl;
			else {
				cout << suin.front() << endl;
				suin.pop();
			}
		else if (command == "size")
			cout << suin.size() << endl;
		else if (command == "empty")
			cout<<suin.empty() << endl;

		else if (command == "front"){
			if (suin.empty())
				cout << -1 << endl;
			else
				cout<<suin.front() << endl;
        }
        else if(command == "back"){
            if (suin.empty())
				cout << -1 << endl;
			else
				cout<<suin.back() << endl;
        }

	}
	return 0;
}