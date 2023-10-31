#include <iostream>

using namespace std; 

int main(){
    int n;
    cin>>n;
    int num[n+1],result[n+1];
    
    fill_n(result,n+1,0);

    for(int i=1;i<=n;i++){
        cin>>num[i]; //입력받기
        int high=0;
    
        for(int j=1;j<=n;j++){
            if(high==num[i]&&result[j]==0){
                result[j]=i;
                break;
            }
            if(result[j]==0) high++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<result[i]<<" ";
    }
    
    return 0;
}