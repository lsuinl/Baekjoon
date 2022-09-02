#include <iostream>
#include <algorithm>

using namespace std;

int suin(string a, string b) {
	if(a.length() == b.length())
		return a < b;
	else
		return a.length() <b.length();
}

string word[20000];
int main() {
	int number;

	cin >> number;
	
	for (int i = 0; i < number; i++)
		cin >> word[i];
	

	sort(word, word+number,suin);
	for(int i=0;i<number;i++){
		if(word[i]==word[i-1])
			continue;
		cout<<word[i]<<"\n";
		//시간에서는 "\n"사용이 endl보다 훨씬 유리함
	}
	return 0;
}
