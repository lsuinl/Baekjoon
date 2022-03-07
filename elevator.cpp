#include <iostream>
#include <math.h>
#include <Windows.h>

using namespace std;

//엘리베이터 만들기
void make(int height, int left, int right, char line[28], char level[28]) {
	cout << line << endl;
	for (int i = height; i >= 1; i--) {
		if (left == i)
			level[6] = *"o";
		else
			level[6] = *" ";
		if (right == i)
			level[19] = *"o";
		else
			level[19] = *" ";

		cout << level << " " << i << endl << line << endl;
	}
}
//엘리베이터 두개;
void make2(int height, int left, int right, int left2, int right2, char line[28], char level[28], char level2[28]) {
	cout << line <<"\t" <<line << endl;
	for (int i = height; i >= 1; i--) {
		if (left == i)
			level[6] = *"o";
		else
			level[6] = *" ";
		if (right == i)
			level[19] = *"o";
		else
			level[19] = *" ";

		if (left2 == i)
			level2[6] = *"o";
		else
			level2[6] = *" ";
		if (right2 == i)
			level2[19] = *"o";
		else
			level2[19] = *" ";
		
		if(i!=height/2)//화살표 만들기
			cout << level << " " << i << "\t";
		else
			cout << level << " " << i << " -> ";

		cout << level2 << " " << i << endl;
		cout<< line << "\t" << line << endl;
	}
}

int main() {
	char line[] = { "##########################" };
	char level[] = { "#           #            #" };
	char level2[] = { "#           #            #" };
	int height, left, right;
	cout << "높이, 왼쪽 위치, 오른쪽 위치를 입력:";
	cin >> height >> left >> right;
	system("cls");
	make(height, left, right, line, level);
	//--------------------------
	int inp = 1, right2=right, left2=left;
	
	//최초 1회
	cout << "현재 위치: ";
	cin >> inp;
	if (inp <= height) {
		if (abs(inp - left) > abs(inp - right))
			right2 = inp;
		else if (abs(inp - left) <= abs(inp - right))
			left2 = inp;
	}
	system("cls");

	//반복
	while (inp != 0) {
		make2(height, left, right, left2, right2, line, level, level2);
		right = right2;
		left = left2;
		cout << "현재 위치: ";
		cin >> inp;
		if (inp <= height) {
			if (abs(inp - left) > abs(inp - right))
				right2 = inp;
			else if (abs(inp - left) <= abs(inp - right))
				left2 = inp;
		}
		system("cls");
	}
	return 0;
}