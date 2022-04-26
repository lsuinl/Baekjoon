#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include <Windows.h>

using namespace std;

//���� �����
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
//�ֺ� ���� �����
void number(int width, int height, int** suin) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (suin[j][i] <= -1) {
				if (j - 1 < 0 && i - 1 < 0) {//���� �� �𼭸�(578
					suin[j + 1][i]++; 
					suin[j + 1][i + 1]++;
					suin[j][i + 1]++;
				}
				else if (j - 1 < 0 && i + 1 == height) {//���� �Ʒ� �𼭸�(235
					suin[j][i - 1]++;
					suin[j + 1][i - 1]++;
					suin[j + 1][i]++;
				}
				else if (j + 1 == width && i - 1 < 0) {//������ �� �𼭸�(467
					suin[j][i + 1]++;
					suin[j - 1][i]++;
					suin[j - 1][i + 1]++;
				}
				else if (j + 1 == width && i + 1 == height) {//������ �Ʒ� �𼭸�(124
					suin[j - 1][i]++;
					suin[j - 1][i - 1]++;
					suin[j][i - 1]++;
				}
				else if (j + 1 == width) {//������(12467
					suin[j - 1][i]++;
					suin[j - 1][i + 1]++;
					suin[j - 1][i - 1]++;
					suin[j][i - 1]++;
					suin[j][i + 1]++;
				}
				else if (j - 1 < 0) {//����(23578
					suin[j + 1][i]++;
					suin[j + 1][i + 1]++;
					suin[j + 1][i - 1]++;
					suin[j][i - 1]++;
					suin[j][i + 1]++;
				}
				else if (i + 1 == height) {//�Ʒ���(12345
					suin[j - 1][i - 1]++;
					suin[j + 1][i - 1]++;
					suin[j][i - 1]++;
					suin[j - 1][i]++;
					suin[j + 1][i]++;
				}
				else if (i - 1 < 0) {//����(45678
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

//�̹��� �����
void dlalwl(int width, int height, int** image) {
	for (int i = 0; i < width + 2; i++) //���� �׵θ�
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0)
				cout << "#"; //���� �׵θ�

			if (image[j][i] <= -1)//����
				cout << "*";
			else if (image[j][i] == 10) //�Է����� ��ĭ
				cout << " ";
			else    //�Է��� ����ĭ
				cout << image[j][i];

			if (j == height - 1)//������ �׵θ�
				cout << '#';
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++) //�Ʒ��� �׵θ�
		cout << "#";
	cout << endl;
}

//--------------------------
int main() {
	//�Է� �޾Ƽ� �԰� �����
	int width, height, count;

	cout << "���ڹ��� ���α���, ���α���, ������ ���� �Է��ϼ���." << endl;
	while (1) {
		cin >> width >> height >> count;

		if (count <= width * height && width > 0 && height > 0)
			break;
		else
			cout << "�ٽ� �Է��ϼ���." << endl;
	}

	//suin �����Ҵ�
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

	//image �����Ҵ�
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
	
	//����ã��
	while (1) {
		dlalwl(width, height, image);
		cout << "��ǥ�� �Է��ϼ���." << endl;
		cin >> x >> y;

		if (x >= 0 && x < width && y >= 0 && y < height) { //������ ũ�� �ȿ��� �Է¹ޱ�
			if (image[x][y] != 10) { //�̹� Ȯ�ε� ��ǥ���� Ȯ��(����üũ)
				number--;
			}

			image[x][y] = suin[x][y];
			number++;

			if (suin[x][y] <= -1) { //����
				system("cls");
				for (int i=0; i < height; i++) { //��� ���� ǥ���ϱ�
					for (int j=0; j < width; j++) {
						if (suin[j][i] <= -1) {
							image[j][i] = suin[j][i];
						}
					}
				}
				dlalwl(width, height, image);
				cout << "�����Դϴ�.";
				break;
			}
			if ((width * height - count) == number) { //��
				system("cls");
				dlalwl(width, height, image);
				cout << "�����մϴ�^^";
				break;
			}

		}
		else
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		system("cls");
	}
}