#include <iostream>
//(��Ŭ���� ȣ����) https://fjvbn2003.tistory.com/37
using namespace std;
/*��Ŭ���� ȣ���� : ū���� �������� ������->������ ���� �������� ��� ������
  �������� 0�� ���ö����� �ݺ��Ѵ�. ->�������� 0�� �� ������ ���� �ִ�����
  + �ִ�����*�ּҰ����=�� ���� ��. ���� �ּҰ����= �� ���� ��/�ִ�����*/


int suin(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << suin(a, b) << endl << (a * b) / suin(a, b);
    return 0;
}