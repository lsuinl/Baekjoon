#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n,m,k,i,j,x,y;
    int arr[301][301];
    cin>>n>>m;

    for(int a=1;a<=n;a++){
        for(int b=1;b<=m;b++){
            cin>>arr[a][b];
        }
    }
    cin>>k;

    for(int a=0;a<k;a++){
        cin>>i>>j>>x>>y;
        int result=0;
        for(int b=i;b<=x;b++){
            for(int c=j;c<=y;c++){
                result+=arr[b][c];
        }
        }
        cout<<result<<"\n";
    }

    return 0;
}