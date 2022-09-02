#include <iostream>

using namespace std;
int suin(string word)
{
	int abc[26] = {0,};

	abc[(int)(word[0])-97]++; //첫번째 알파벳

	for (int i = 1; i < word.length(); i++)
	{
		if (word[i - 1] == word[i]) //이전 알파벳과 동일한 경우에
			continue;
		abc[word[i]-97]++; //다르면 빠져나와서 알파벳쪽 증가
	}

	for (int i = 0; i < 26; i++)
	{
		if (abc[i] > 1)
			return 0;
	}
	return 1;
}

int main()
{
	int n, result = 0;
	string word;
	cin >> n;
	for (int i = 0; i <n; i++)
	{
		cin>>word;
		result += suin(word);
	}
	cout << result;

	return 0;
}


// int main() {
// 	int inp;
// 	string word;
// 	int count = 0;
// 	cin >> inp;

// 	for (int i = 0; i < inp; i++) {
// 		cin >> word;
// 		bool abc[26] = { false, };
// 		abc[(int)(word[0]) - 97] = true;

// 		for (int i = 1; i < word.size(); i++) {
// 			if (word[i] == word[i - 1]) {
// 				continue;
// 			}
// 			else if (word[i] != word[i - 1] && abc[(int)(word[i]) - 97] == true) {
// 				count++;
// 				break;
// 			}
// 			else {
// 				abc[(int)(word[i]) - 97] = true;
// 			}
// 		}
// 	}
// 	cout << inp - count;

// 	return 0;
// }