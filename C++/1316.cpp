#include <iostream>
//https://beginnerdeveloper-lit.tistory.com/104
//¾î·Á¿ý
using namespace std;

int main() {
	int inp;
	string word;
	int count = 0;
	cin >> inp;

	for (int i = 0; i < inp; i++) {
		cin >> word;
		bool abc[26] = { false, };
		abc[(int)(word[0]) - 97] = true;

		for (int i = 1; i < word.size(); i++) {
			if (word[i] == word[i - 1]) {
				continue;
			}
			else if (word[i] != word[i - 1] && abc[(int)(word[i]) - 97] == true) {
				count++;
				break;
			}
			else {
				abc[(int)(word[i]) - 97] = true;
			}
		}
	}
	cout << inp - count;

	return 0;
}