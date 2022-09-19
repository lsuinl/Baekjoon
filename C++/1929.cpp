// #include <iostream>

// using namespace std;
// //재귀: 왜 재귀하냐?
// int prime(int a, int b){ 
//     if(a==1) //처음부터 1인 경우
//         return 1;
//     else if(a==2)//2는 소수
//         return 2;
//     else if(a%b!= 0)//나누어 떨어지나요?
//         return prime(a, b-1); 
//     else if(a%b==0 && b==1) //나누어 떨어지지만 나눈 숫자가 1인가요?
//             return a;
//     else   //나누어떨어지나요?(소수아님._
//         return 1;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int m,n;
//     cin>>m>>n;
//     for(int i=m;i<=n;i++){
//         if(prime(i,i-1)!=1) //반환값이 1이 아닌경우라면 그것은 소수~
//             cout<<i<<"\n";
//     }
//     return 0;
// }

//2: 이중반복문
// #include <iostream>

// using namespace std;

// int prime(int a){
//     for(int i=2;i<a;i++){
//         if(a%i==0)
//             return 0;
//     }
//     return a;
// }

// int main(){
//     int m,n;
//     cin>>m>>n;
//     for(int i=m;i<=n;i++){
//         if(prime(i)!=0)
//             cout<<i<<"\n";
//     }
//     return 0;
// }

//참고,, 하슈
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool primeNum[1000001];
int main(void) {
	//input
	int M, N;
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		primeNum[i] = true;
	}
	//perform
	primeNum[1] = false;
	for (int i = 2; i <= sqrt(N); i++) {
		for (int j = i + i; j <= N; j += i) {
			primeNum[j] = false;
		}
	}
	//output
	for (int i = M; i <= N; i++) {
		if (primeNum[i]) cout<<i<<"\n";
	}
}