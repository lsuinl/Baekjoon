#include <iostream>
#include <string> //to_string()�Լ�
#include <algorithm> //sort �Լ� 

//sort �Լ� ����غ���
using namespace std;
/*
int main() {
    char n[11];
    cin >> n;
    for (int j = 0; j < strlen(n); j++) {
        for (int i = 0; i < strlen(n); i++) {
            int z;
            if (n[j] > n[i]) {
                z = n[i];
                n[i] = n[j];
                n[j] = z;
            }
        }
    }

    cout << n;

    return 0;
}*/

bool compare(char a, char b) {
    return a > b;
}

int main() {
    string a;
    int n;
    cin >> n;

    //n�� string������ ��ȯ�ؼ� a�� ����
    a = to_string(n);

    //a�� ���ۺ��� ������ (compare�� �������Ǻ�) ���ؼ� ����
    //https://cocoon1787.tistory.com/189
    //���̸� ��������, (��=�� ū ��)?????�³�
    sort(a.begin(), a.end(), compare);

    cout << a;
}