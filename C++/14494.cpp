// #include <iostream>

// using namespace std;

// int main(){
//     int n,m;
//     long long dp[1001][1001];
//     dp[1][1]=1; 
//     cin>>n>>m;
//     for(int i=2;i<=n;i++){
//         for(int j=2;j<=m;j++){
//             if(i==2) dp[i-1][j]=1;
//             if(j==2) dp[i][j-1]=1;
//             dp[i][j]=(dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1])%1000000007;
//         }
//     }
//     cout<<dp[n][m];
//     return 0;
// }

#include <iostream>
#define MOD ((int)1e9+7) 

using namespace std; 

int d[(int)1e3+1][(int)1e3+1]; 

int main() 
{ 

  int n, m; 
  cin >> n >> m; 

  d[0][0] = 1; 
  for (int i=1; i<=n; i++) 
  { 
    for (int j=1; j<=m; j++) 
    { 
      d[i][j] = d[i-1][j-1]; 
      d[i][j] += d[i][j-1]; 
      d[i][j] %= MOD; 

      d[i][j] += d[i-1][j]; 
      d[i][j] %= MOD; 
    } 
  } 

  cout << d[n][m]; 
} 