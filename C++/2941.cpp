#include <iostream>

using namespace std;

int main() {
	string word;
	cin >> word;
	int result = word.size();
	for (int i = 1; i < word.size(); i++) {
		if (word[i - 1] == 'c' || word[i - 1] == 'd') {
			if (word[i] == '-')
				result--;
		}

		if (word[i - 1] == 'c' || word[i - 1] == 's' || word[i - 1] == 'z')
			if (word[i] == '=') {
				result--;
				if (word[i - 1] == 'z' && word[i - 2] == 'd')
					result--;
			}
			if (word[i - 1] == 'l' || word[i - 1] == 'n') {
				if (word[i] == 'j')
					result--;
			}
	}
	cout << result;

	return 0;
}