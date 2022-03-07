#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int b[2], d[2], j[2], bmove=0, dmove=0;
	cin >> b[0] >> b[1];
	cin >> d[0] >> d[1];
	cin >> j[0] >> j[1];

	dmove = fabs(j[0] - d[0]) + fabs(j[1] - d[1]);
	bmove = max(fabs(j[0] - b[0]), fabs(j[1] - b[1]));
	if (dmove > bmove)
		cout << "bessie";
	else if (dmove < bmove)
		cout << "daisy";
	else if(dmove==bmove)
		cout << "tie";

	return 0;
}