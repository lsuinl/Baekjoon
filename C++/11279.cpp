#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    priority_queue<int, vector<int>> q;
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==0 && q.size()==0){
            cout<<0<<"\n";
        }
        else if(x==0){
            cout<<q.top()<<'\n';
            q.pop();
        }
        else{
            q.push(x);
        }
    }

    return 0;
}