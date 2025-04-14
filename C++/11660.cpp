#include <iostream>

using namespace std;


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int map[1025][1025];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int num;
            cin>>num;
            map[i][j]=map[i-1][j]+map[i][j-1]+num-map[i-1][j-1];
        }
    }

    for(int i=0;i<m;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int result = map[x2][y2] -(map[x2][y1-1]+map[x1-1][y2]-map[x1-1][y1-1]);
        cout<<result<<"\n";
    }

    return 0;
}