#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

//지뢰 만들기
void make(int width, int height, int count, int** suin) {
	srand(time(NULL));
	int wlfhlx, wlfhly;
	for (int i = 0; i < count; i++) {
		wlfhlx = rand() % width;
		wlfhly = rand() % height;
		if (suin[wlfhlx][wlfhly] == -10)
			i--;
		suin[wlfhlx][wlfhly] = -10;
	}
}
//주변 숫자 만들기
void number(int width, int height, int** suin) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (suin[j][i] <= -1) {
				if (j - 1 < 0 && i - 1 < 0) {//왼쪽 위 모서리(578
					suin[j + 1][i]++; 
					suin[j + 1][i + 1]++;
					suin[j][i + 1]++;
				}
				else if (j - 1 < 0 && i + 1 == height) {//왼쪽 아래 모서리(235
					suin[j][i - 1]++;
					suin[j + 1][i - 1]++;
					suin[j + 1][i]++;
				}
				else if (j + 1 == width && i - 1 < 0) {//오른쪽 위 모서리(467
					suin[j][i + 1]++;
					suin[j - 1][i]++;
					suin[j - 1][i + 1]++;
				}
				else if (j + 1 == width && i + 1 == height) {//오른쪽 아래 모서리(124
					suin[j - 1][i]++;
					suin[j - 1][i - 1]++;
					suin[j][i - 1]++;
				}
				else if (j + 1 == width) {//오른쪽(12467
					suin[j - 1][i]++;
					suin[j - 1][i + 1]++;
					suin[j - 1][i - 1]++;
					suin[j][i - 1]++;
					suin[j][i + 1]++;
				}
				else if (j - 1 < 0) {//왼쪽(23578
					suin[j + 1][i]++;
					suin[j + 1][i + 1]++;
					suin[j + 1][i - 1]++;
					suin[j][i - 1]++;
					suin[j][i + 1]++;
				}
				else if (i + 1 == height) {//아래쪽(12345
					suin[j - 1][i - 1]++;
					suin[j + 1][i - 1]++;
					suin[j][i - 1]++;
					suin[j - 1][i]++;
					suin[j + 1][i]++;
				}
				else if (i - 1 < 0) {//위쪽(45678
					suin[j - 1][i + 1]++;
					suin[j + 1][i + 1]++;
					suin[j][i + 1]++;
					suin[j - 1][i]++;
					suin[j + 1][i]++;
				}
				else {
					suin[j - 1][i]++;
					suin[j - 1][i + 1]++;
					suin[j - 1][i - 1]++;
					suin[j][i - 1]++;
					suin[j][i + 1]++;
					suin[j + 1][i]++;
					suin[j + 1][i + 1]++;
					suin[j + 1][i - 1]++;
				}
			}
		}
	}
}

//이미지 만들기
void dlalwl(int width, int height, int** image) {
	for (int i = 0; i < width + 2; i++) //위쪽 테두리
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0)
				cout << "#"; //왼쪽 테두리

			if (image[j][i] <= -1)//지뢰
				cout << "*";
			else if (image[j][i] == 10) //입력전에 빈칸
				cout << " ";
			else    //입력한 숫자칸
				cout << image[j][i];

			if (j == height - 1)//오른쪽 테두리
				cout << '#';
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++) //아래쪽 테두리
		cout << "#";
	cout << endl;
}

//--------------------------
int main() {
	//입력 받아서 규격 만들기
	int width, height, count;

	cout << "지뢰밭의 가로길이, 세로길이, 지뢰의 수를 입력하세요." << endl;
	while (1) {
		cin >> width >> height >> count;

		if (count <= width * height && width > 0 && height > 0)
			break;
		else
			cout << "다시 입력하세요." << endl;
	}

	//suin 동적할당
	int** suin = new int* [width];
	for (int i = 0; i < width; i++) {
		suin[i] = new int[height];
	}
	for (int e = 0; e < width; e++) {
		for (int j = 0; j < height; j++) {
			suin[j][e] = 0;
		}
	}

	make(width, height, count, suin);;
	number(width, height, suin);
	//-------------------------------------------------
	
	int x, y;
	int number = 0;

	//image 동적할당
	int** image = new int* [width];
	for (int i = 0; i < width; i++) {
		image[i] = new int[height];
	}
	for (int e = 0; e < width; e++) {
		for (int j = 0; j < height; j++) {
			image[j][e] = 10;
		}
	}

	system("cls");

	//-----------------------------------------------
	
	//지뢰찾기
	while (1) {
		dlalwl(width, height, image);
		cout << "좌표를 입력하세요." << endl;
		cin >> x >> y;

		if (x >= 0 && x < width && y >= 0 && y < height) { //지정된 크기 안에서 입력받기
			if (image[x][y] != 10) { //이미 확인된 좌표인지 확인(개수체크)
				number--;
			}

			image[x][y] = suin[x][y];
			number++;

			if (suin[x][y] <= -1) { //지뢰
				system("cls");
				for (int i=0; i < height; i++) { //모든 지뢰 표현하기
					for (int j=0; j < width; j++) {
						if (suin[j][i] <= -1) {
							image[j][i] = suin[j][i];
						}
					}
				}
				dlalwl(width, height, image);
				cout << "지뢰입니다.";
				break;
			}
			if ((width * height - count) == number) { //끝
				system("cls");
				dlalwl(width, height, image);
				cout << "축하합니다^^";
				break;
			}

		}
		else
			cout << "잘못 입력하셨습니다" << endl;
		system("cls");
	}
}