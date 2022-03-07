#include <iostream>
//나는 속았다 이 간사한 놈
using namespace std;

int main() {
	int count, suin, avg=0;

	cin >> count;
	for (int i = 0; i < count; i++) {
		if (count == 0) {  //0이면 끝
			cout << "divide by zero";
			break;
		}
		cin >> suin;
		avg += suin;
	}
	if (avg == 0)
		cout << "divide by zero";
	else
		cout << "1.00";

	return 0;
}