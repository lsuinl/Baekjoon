//https://blog.naver.com/tipsware/221326634400
#include <iostream>

using namespace std;

void main() {
	int arr[2][3] = { {1,2,3},{4,5,6} };
	int (*p)[3] = arr;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			//cout<<(*(p + i))[j]; //()로 결정되는 우선순위에 유의
			cout<<p[i][j];
		}
		cout << endl;
	}
}

/*
void main() {
	int arr[2][3] = { {1,2,3}, {4,5,6} };
	int* p = (int*)arr; //형변환

	for (int i = 0; i < 6; i++) {
		cout << *(p + i);
		if (i == 2)
			cout << endl;
	}
}*/
