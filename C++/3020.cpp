// 초안. 시간초과
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
    cout.tie(NULL);

    int N,H,result=500000,count = 1; //N=길이, H=높이
    
    cin>>N;
    cin>>H; 

    vector<int> top(N/2); 
    vector<int> bottom(N/2);
    for(int i=0;i<=N/2;i++)
        cin>>bottom[i]>>top[i];
    
    sort(top.begin(),top.end());
    sort(bottom.begin(),bottom.end());

    for(int i=1;i<=H;i++){
        int cur = N -( ( lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin()) + (lower_bound(top.begin(), top.end(), H - i + 1) - top.begin()));     
        if(cur < result) {
            result = cur;
            count = 1;
        }
        else if(cur == result) count++;
    }
    cout<<result<<" "<<count;
    return 0;
    
}

//https://9x211x2.tistory.com/43