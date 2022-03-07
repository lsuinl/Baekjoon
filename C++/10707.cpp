#include <iostream>

using namespace std;

int main() {
	int xmoney, ydefault, ymax, yplus, p;
	cin >> xmoney >> ydefault >> ymax >> yplus >> p;
	xmoney = xmoney * p;
	if (p > ymax) {
		ydefault = ydefault + (p - ymax) * yplus;
	}
	
	if (ydefault > xmoney)
		cout << xmoney;
	else
		cout << ydefault;
}