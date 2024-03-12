#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//한번 넣으면 빠져나올 수 없다!

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> stacks;
	vector<char> answer;
	bool no = false;
	int max=1;
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		while(1){
			if(stacks.empty()){
				answer.push_back('+');
				stacks.push(max);
				max++;
			}
			
			if(stacks.top()==a){
				answer.push_back('-');
				stacks.pop();	
				break;
			}
			else if (stacks.top()>a) {
				no = true;
				break;
			}
			else{
				answer.push_back('+');
				stacks.push(max);	
				max++;
			}
		}
	}
	
	if (no) cout << "NO";
	else for (int i = 0; i < answer.size(); i++) cout << answer[i] << "\n";

	return 0;
}