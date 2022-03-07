#include <iostream>

using namespace std;

int main() {
	int hour, min, need, rhq;
	cin >> hour >> min;
	cin >> need;
	if (min + need >= 60) {
		rhq = (min + need) / 60;
		min = min + need - (60 * rhq);
		if (hour + rhq >= 24)
			hour = hour + rhq - 24;
		else
			hour=hour+rhq;
	}
	else {
		min = min + need;
	}
	cout << hour << " " << min;
	return 0;
}