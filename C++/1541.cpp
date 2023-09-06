#include <iostream>

using namespace std;

int main(){
    string maths;
    cin>>maths;
    int start=0;
    int minussum=0,sum=0;
    bool minuscheck=false;
    for(int i=0;i<maths.size();i++){
        if(maths[i]=='-'&&minuscheck==false){ //마이너스와의 첫 만남
            sum+=stoi(maths.substr(start,i));
            start=i+1;
            minuscheck=true;
        }
        else if(maths[i]=='+'||maths[i]=='-'||i+1==maths.size()){
            if(minuscheck==true)     minussum+=stoi(maths.substr(start,i+1));
            else sum+=stoi(maths.substr(start,i+1));
            start=i+1;
        }

    }
    cout<<sum-minussum;
    return 0;
}
//최솟값을 만드는 방법= 마이너스(-)가 나오면 뒤에 나오는 모든 수식들을 더해서 큰 수로 만들어준다..
