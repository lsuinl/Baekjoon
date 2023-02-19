#include <iostream>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    //선언  
    int n,m;
    bool switchs[100];
    //입력받기
    cin>>n;
    for(int i=0;i<n;i++){
        int onoff;
        cin>>onoff;
    
        switchs[i]=(onoff==1)?true:false;
    }
    cin>>m;
    //처리하기
    for(int i=0;i<m;i++){
        int gender, number;
        cin>>gender>>number;
        if(gender==1){ //남학생
        for(int i=number-1;i<n;i+=number){ //배수 변환
            switchs[i]=!switchs[i];            
        }
        }
        else{ //여학생
        int center=number-1; //인덱스는 -1번
        switchs[center]=!switchs[center]; //중앙은 먼저 변환
        for(int i=1;i<n;i++){ 
            if(center-i<0 || center+i>n-1) break; //범위를 벗어나면 break
            else if(switchs[center-i]==switchs[center+i]){ //조건이 일치하면 변환
                switchs[center-i]=!switchs[center-i];
                switchs[center+i]=!switchs[center+i];
            }
            else break; //조건에 만족하지 못하는 경우 break
        }
        }
    }
    //결과출력
    for(int i=0;i<=(n/20);i++){
        for(int j=(i*20);j<((i*20+20)<n?(i*20+20):n);j++){
            cout<<switchs[j]<<' ';
        }
        cout<<'\n';
    }
    return 0;

}