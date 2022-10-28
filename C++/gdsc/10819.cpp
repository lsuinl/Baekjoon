#include <iostream>
#include <algorithm>
//https://codingwell.tistory.com/33

using namespace std;

int main(){
    int n, result=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    while(next_permutation(arr,arr+n)){ //짱짱맨 순열을구함.
        int sum=0;
        for(int i=1;i<n;i++)
            sum+=abs(arr[i-1]-arr[i]);
        if(result<sum)
            result=sum;
    }
    cout<<result;
    return 0;
}
