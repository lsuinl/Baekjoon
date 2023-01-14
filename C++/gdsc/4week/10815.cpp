#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> suin;

// int findnumber(int number){
//     int low=0, high=suin.size()-1;
//     int mid = suin.size()/2;
//     int n=1;
//     while(low<=high){
//     if(suin[mid]<number)
//         high=mid-1;
//     else if(suin[mid]>number)
//         low=mid+1;
//     else
//         return 1;
//     }
//     return 0;
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,number;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>number;
        suin.push_back(number);
    }
    sort(suin.begin(),suin.end());
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>number;
        int result= binary_search(suin.begin(),suin.end(),number);
        cout<<result<<" ";
    }
    return 0;
}