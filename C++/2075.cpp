#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
//넘모 멋지다
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);

    //오름차순
    priority_queue<int, vector<int>, greater<int>> q;
    int n;

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int number;
            cin>>number;
            q.push(number);
            if(q.size()>n){
                q.pop(); //가장 작은 수 지우기
            }
        }
    }
    cout<<q.top();


    return 0;
}