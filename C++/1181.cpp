#include <iostream>
#include <string.h>

using namespace std;
//시간초과 ㅜㅜㅋㅋㅋㅋㅋㅋㅋㅋㅋ

void suin(int number, char word[20000][50]) {
	//길이순으로 정렬
	int chart[50];
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			chart[i] = 1;
			if (strlen(word[i]) > strlen(word[j]))
				chart[i]++;
		}
	}
	//사전순으로
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (chart[i] == chart[j]) {
				for (int z = 0; z < strlen(word[i]); z++) {
					if (word[i][z] > word[j][z]) {
						chart[i]++;
						break;
					}
					else if (word[i][z] < word[j][z]) {
						chart[j]++;
						break;
					}
				}
			}
		}
	}
	//chart==1부터 출력..ㅎ
	for (int i = 0; i < number; i++) {
		for (int j = 1; j <= number; j++) {
			if (chart[i] == j)
				cout << word[chart[i]];
		}
	}
}


int main() {
	int number;
	char word[20000][50];
	cin >> number;
	
	for (int i = 0; i < number; i++) {
		cin >> word[i];
	}

	suin(number, word);

	return 0;
}
//방법 1
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareWith(string a, string b){
  if(a.length() == b.length())
    return a<b;
  return a.length()<b.length();
}

int main(){
  int N;
  vector<string> vec;  
  cin>>N;
  for(int i=0; i<N; i++){
    string str;
    cin>>str;
    if(find(vec.begin(), vec.end(), str) == vec.end())
      vec.push_back(str);
  }
  sort(vec.begin(), vec.end(), compareWith);

  for(int i=0; i<vec.size(); i++){
    cout<<vec[i]<<'\n';
  }
}*/


//방법 2

/*
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string a[20000];

bool compare(string a, string b) {
	if (a.length() < b.length()) {
		return 1;
	}
	else if (b.length() < a.length()) {
		return 0;
	}
	else {
		return a < b;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);

	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] == a[i - 1]) continue;
		cout << a[i] << ' ';
	}

}*/