#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin>>n;
        vector<long long> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<long long> sorts=nums;
    sort(sorts.begin(),sorts.end());

    map<int, int> result;
    int rank = 0;
    for(auto num : sorts) {
        if(result.find(num) == result.end()) {
            result[num] = rank++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<result[nums[i]]<<" ";
    }
    return 0;
}

