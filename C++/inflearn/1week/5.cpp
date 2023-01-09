#include <iostream>
using namespace std;

class study{//구조체를 추천.
    public:
    int st;
    int et;
    int effic;
};

int dp(study chusu[], int index){
    int result;
    return result;
}

int main(){
    int N,M,R;
    cin>>N>>M>>R;
    study chusu[M];
    for(int i=0;i<M;i++){
        cin>>chusu[i].st>>chusu[i].et>>chusu[i].effic;
        chusu[i].et+=R;
    }
    cout<<dp(chusu, 0);
    return 0;
}