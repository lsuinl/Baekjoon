// #include <iostream>

// using namespace std;

// int main(void){
//     long n;
//     int repeat=0;
//     cin>>n;

//     while(n!=1){
//     if(n%3==0)
//         n/=3;
//     else if(n%2==0)
//         n/=2;
//     else
//         --n;
//     repeat++;
//     }

//     cout<<repeat;

//     return 0;
// }
//최소 경우의 수를 구해야하므로 배열을 만들어서 따로 해야댐, 
//DP(Dinamic Programming) 공부
//다시보기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n ;
	vector<int> dp(n + 1);

	//bottom-up
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (!(i % 3)) dp[i] = min(dp[i],dp[i / 3] + 1);
		if (!(i % 2)) dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[n] << endl;
	return 0;
}
