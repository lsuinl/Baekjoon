#include <iostream>

using namespace std;

typedef struct people{ 
    string id;
    string passward;
} people;

//회원가입
void sign_up(people information[100]){ //아이디가 중복인 경우 확인할 것
        int i=0, end=0; 
        string chpassward;
        while(1){ //저장할 위치 설정
            if(information[i].id=="0")
                break;
            else
                i++;
        }
        while(1){
        cout<<"id: ";
        cin>>information[i].id;
        cout<<"passward: ";
        cin>>information[i].passward;
        cout<<"passward check: ";
        cin>>chpassward;

        if(chpassward!=information[i].passward){ //비밀번호 확인이 다를 때
            cout<<"비밀번호가 서로 다릅니다"<<endl;
            continue;
        }
        
        for(int j=0; j<i;j++){ //아이디가 중복일 때
            if(information[i].id==information[j].id){
                cout<<"이미 같은 아이디가 존재합니다"<<endl;
                end=1;
                break;
            }
        }
        if(end==0){
            break;
        }
   }
}

//로그인
void login(people information[100], people check){
            while(1){
            cout<<"id: ";
            cin>>check.id;
            cout<<"passward: ";
            cin>>check.passward;

            //아이디 먼저 확인
            int i=0, end=0;
            while(information[i].id!="0"){ 
                if(information[i].id==check.id){ //아이디 확인
                    if(information[i].passward==check.passward){ //비밀번호 확인
                        cout<<"로그인 성공";
                        end=1;
                        break;
                    }
                    else{
                        break;
                    }
                }
                else{ //아이디가 다름->다음 데이터로 확인
                    i++;
                    continue;
                }
            }
            if(end==0){
                cout<<"다시 확인하세요"<<endl;
                continue;
            }
            else if(end==1){
                break;
            }
}
}

//회원가입. 로그인 선택
void choice(people information[100], people check){
    while(1){
        int choose;
        cout<<"회원가입을 하시려면 1, 로그인을 하시려면 2를 입력해주세요 :"<<endl;
        cin>>choose;

        if(choose==1){
            sign_up(information); //회원가입 후 다시 선택창으로
            continue;
        }
        else if(choose==2){ //로그인성공 후 나가기.
            login(information,check);
            break;
        }
        else{ //다른 수 입력시 다시 
            continue;
        }
    }
}


int main(){
    people information[100]={"0"}, check; //포인터함수로 정보 저장하기,동적할당하기, 비밀번호 암호화하기
    choice(information, check);
}