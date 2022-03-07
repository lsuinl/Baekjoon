#include <iostream>

using namespace std;

int main() {
	int biryear, birmonth, birday;
	int year, month, day;
	int man, count, yean;

	cin >> biryear >> birmonth >> birday;
	cin >> year >> month >> day;
	if (birmonth < month)//积老瘤巢
		man = year - biryear;
	else if (birmonth == month && birday <= day)//积老瘤巢
		man = year - biryear;
	else
		man = year - biryear-1;
	
	count=year-biryear+1;
	
	yean=year-biryear;
	cout << man << endl << count << endl << yean;
	return 0;
}