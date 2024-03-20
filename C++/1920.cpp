#include <iostream>
#include <algorithm>
using namespace std;

int binary(int A[], int n, int m){
    int high=n-1, low=0, mid=0;
    while(low<=high){
        mid=(high+low)/2;
        if(A[mid]==m)
            return 1;
        else if(A[mid]>m)
            high=mid-1;
        else
            low=mid+1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);        
    int n,m, r;
    cin>>n;
    int *A= new int[n];
    for(int i=0;i<n;i++)    
        cin>>A[i];
    sort(A,A+n);
    cin>>m;
    for(int i=0;i<m;i++) {
        cin>>r; 
        cout<<binary(A,n,r)<<'\n';
    }
    return 0;
}