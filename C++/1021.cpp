#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n,m,result=0;
    cin>>n>>m;
    deque<int> dq;
    for(int i=1;i<=n;i++){ //만들기
        dq.push_back(i);
    }
    for(int i=0;i<m;i++){ //입력받고 계산하기
        int number,minc,mind;
        cin>>number;
        if(dq.front()==number){
            dq.pop_front();
        }
        else{
        deque<int> cdq=dq;
        for(int a=0;a<cdq.size();a++){
            cdq.push_back(cdq.front());
            cdq.pop_front();
            if(cdq.front()==number){
                cdq.pop_front();
                minc=a+1;
                break;
            }
        }
        deque<int> ddq=dq;
        for(int a=0;a<ddq.size();a++){
            ddq.push_front(ddq.back());
            ddq.pop_back();
            if(ddq.front()==number){ 
                ddq.pop_front();
                mind=a+1;
                break;
            }
        }
        if(mind<minc){
            dq=ddq;
            result+=mind;
        }
        else{
            dq=cdq;
            result+=minc;
        }
        }
    }
    cout<<result;
    return 0;
}