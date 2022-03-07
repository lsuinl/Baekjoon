#include <iostream>

using namespace std;

int main() {
	int  month, day;
	cin >> month >> day;
	if (2 > month)
		cout << "Before";
	else if (2 == month && 18 > day)
		cout << "Before";
	else if (2 == month && 18 == day)
		cout << "Special";
	else
		cout << "After";

	return 0;
}