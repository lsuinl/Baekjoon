#include <iostream>
#include <cstring>
//#include <cstring> -> strcmp(s1,s2)==비교해서 s1이 앞이면 음수, 같으면0, 뒤면양수반환
using namespace std;
int main() {
	char name[20][13];
	string suin;
	int a;

	cin >> a;
	cin >> name[0];
	for (int i = 1; i < a; i++) {
		cin >> name[i];
		int sttr = strcmp(name[i - 1], name[i]);
		if (sttr < 0)
			suin = "INCREASING";
		else if (sttr > 0)
			suin = "DECREASING";
	}
	for (int i = 1; i < a; i++) {
		int sttr = strcmp(name[i - 1], name[i]);
		if (suin == "INCREASING" && sttr > 0)
			suin = "NEITHER";
		else if (suin == "DECREASING" && sttr < 0)
			suin = "NEITHER";
	}

	cout << suin;
}