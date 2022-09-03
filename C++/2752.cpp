#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
	return a<b;
}

int main(){
	int number[3]; 
	//반복문으로도 입출력 가능
	cin>>number[0]>>number[1]>>number[2];
	sort(number, number+3, compare);
	cout<<number[0]<<" "<<number[1]<<" "<<number[2];

	return 0;
}

// int main() {
// 	int a, b, c, empty;
// 	cin >> a >> b >> c;

// 	if (a > b) {
// 		empty = a;
// 		a = b;
// 		b = empty;
// 	}
// 	if (b > c) {
// 		empty = b;
// 		b = c;
// 		c = empty;
// 	}
// 	if (a > b) {
// 		empty = a;
// 		a = b;
// 		b = empty;
// 	}

// 	cout <<a << " " << b<< " " << c;

// 	return 0;
// }