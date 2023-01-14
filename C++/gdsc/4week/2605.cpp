#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> suin;
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        int number,index;
        cin>>number;
        suin.insert(suin.begin()+number,i);
    }
    for(int i=suin.size()-1;i>=0;i--){
        cout<<suin[i]<<" ";
    }
    return 0;
}