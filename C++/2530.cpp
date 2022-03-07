#include <iostream>
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=zsujinz&logNo=220930410311
using namespace std;

int main() {
	int hour, minute, second, need, day;
	cin >> hour >> minute >> second;
	cin >> need;

	second += need;
	minute += second / 60;
	hour += minute / 60;

	cout << hour % 24 << " " << minute % 60 << " " << second % 60;

	return 0;
}