#include <iostream>

using namespace std;

typedef struct people{ 
    string id;
    string passward;
} people;

typedef struct movie{
    string genre;
    string name;
}movie;

//영화 저장
/*void setting(movie watch[21]){
    for(int i=0; i<21;){
        if(i==0 || i==1 || i==2){
            watch[i].genre="판타지";
            if(i==0){
                watch[i].name="신과 함께";
                watch[i+1].name="원더우면";
                watch[i+2].name="판의 미로";
            }
        }
        else if(i==3 || i==4 || i==5){
            watch[i].genre="공포";
            if(i==3){
                watch[i].name="컨저링";
                watch[i+1].name="에나벨";
                watch[i+2].name="허쉬";
            }
        }
        else if(i==6 || i==7 || i==8){
            watch[i].genre="로맨스";
            if(i==6){
                watch[i].name="어바웃 타임";
                watch[i+1].name="오만과 편견";
                watch[i+2].name="플립";
            }
        }
        else if(i==9 || i==10 || i==11){
            watch[i].genre="스릴러";
            if(i==9){
                watch[i].name="기생충";
                watch[i+1].name="타짜";
                watch[i+2].name="노인을 위한 나라는 없다";
            }
        }
        else if(i==12 || i==13 || i==14){
            watch[i].genre="코미디";
            if(i==12){
                watch[i].name="세 얼간이";
                watch[i+1].name="극한직업";
                watch[i+2].name="싱크홀";
            }
        }
        else if(i==15 || i==16 || i==17){
            watch[i].genre="액션";
            if(i==15){
                watch[i].name="헝거게임";
                watch[i+1].name="암살";
                watch[i+2].name="스파이더맨";
            }
        }
        else if(i==18 || i==19 || i==20){
            watch[i].genre="SF";
            if(i==0){
                watch[i].name="인터스텔라";
                watch[i+1].name="매드맥스";
                watch[i+2].name="마션";
            }
        }
    }
}*/
//-------------------------------------------------
//회원가입
void sign_up(people *suinformation){ 
        int i=0, end=0; 
        string chpassward;
        while(1){ //저장할 위치 설정
            if(suinformation[i].id=="0")
                break;
            else
                i++;
        }
        while(1){
        cout<<"id: ";
        cin>>suinformation[i].id;
        cout<<"passward: ";
        cin>>suinformation[i].passward;
        cout<<"passward check: ";
        cin>>chpassward;

        if(chpassward!=suinformation[i].passward){ //비밀번호 확인이 다를 때
            cout<<"비밀번호가 서로 다릅니다"<<endl;
            continue;
        }
        
        for(int j=0; j<i;j++){ //아이디가 중복일 때
            if(suinformation[i].id==suinformation[j].id){
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
void login(people* suinformation){
            people check;
            while(1){
            cout<<"id: ";
            cin>>check.id;
            cout<<"passward: ";
            cin>>check.passward;

            int i=0, end=0;
            while(suinformation[i].id!="0"){ 
                if(suinformation[i].id==check.id){ //아이디 확인
                    if(suinformation[i].passward==check.passward){ //비밀번호 확인
                        cout<<"로그인 성공";
                        end=1;
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
void choice(){
    people information[100]={0};
    people *suinformation=information;
    int choose;
    while(1){
        cout<<"회원가입을 하시려면 1, 로그인을 하시려면 2를 입력해주세요 :"<<endl;
        cin>>choose;

        if(choose==1){
            sign_up(suinformation); //회원가입 후 다시 선택창으로
            continue;
        }
        else if(choose==2){ //로그인성공 후 나가기.
            login(suinformation);
            break;
        }
        else{ //다른 수 입력시 다시 
            continue;
        }
    }
}
//---------------------------------------------------------------------------
/*
//전체보기
void full(movie watch[21]){
    string moviee;
    int check=0;
    //영화 나열하기
    cout<<"원하는 영화를 선택해주세요"<<endl;
    for(int i=0;i<20;i++){
        cout<<watch[i].name<<", ";
    }
    cout<<watch[20].name<<endl<<"영화: ";
    //영화 입력받기
    while(1){
    cin>>moviee;
    for(int i=0;i<21;i++){
        if(moviee==watch[i].name){
            cout<<"제목: "<<watch[i].name<<endl;
            cout<<"장르: "<<watch[i].genre;
            check=1;
        }
    }
    if(check==0){
        cout<<"다시 입력하세요"<<endl<<"영화: ";
        continue;
    }
    else{
        break;
    }
    }
    
}

//장르별
void category(movie watch[21]){
    string genree, moviee;
    //장르 나열
    cout<<"원하는 장르를 입력해주세요"<<endl;
    for(int i=0;i<21;i=i+3){
        cout<<watch[i].genre<<", ";
    }
    cout<<endl<<"장르: ";
    //장르 입력받기
    cin>>genree;
    cout<<"원하는 영화를 선택해주세요"<<endl;
    
    if(genree=="판타지"){
        cout<<watch[0].name<<", "; cout<<watch[1].name<<", "; cout<<watch[2].name;   
    }
    else if(genree=="공포"){
        cout<<watch[3].name<<", "; cout<<watch[4].name<<", "; cout<<watch[5].name;
    }
    else if(genree=="로맨스"){
        cout<<watch[6].name<<", "; cout<<watch[7].name<<", "; cout<<watch[8].name;
    }
    else if(genree=="스릴러"){
        cout<<watch[9].name<<", "; cout<<watch[10].name<<", "; cout<<watch[11].name;
    }
    else if(genree=="코미디"){
        cout<<watch[12].name<<", "; cout<<watch[13].name<<", "; cout<<watch[14].name;
    }
    else if(genree=="액션"){
        cout<<watch[15].name<<", "; cout<<watch[16].name<<", "; cout<<watch[17].name;
    }
    else if(genree=="SF"){
        cout<<watch[18].name<<", "; cout<<watch[19].name<<", "; cout<<watch[20].name;
    }
    else{
    }
    //영화 입력받기
    int check;
    cout<<endl<<"영화: ";
    while(1){
    cin>>moviee;
    for(int i=0;i<21;i++){
        if(moviee==watch[i].name){
            cout<<"제목: "<<watch[i].name<<endl;
            cout<<"장르: "<<watch[i].genre;
        }
    }
        if(check==0){
        cout<<"다시 입력하세요"<<endl<<"영화: ";
        continue;
    }
    else{
        break;
    }
}
}

//선택화면 2
void choice2(movie watch[21]){
    int choice;
    while(choice!=1 || choice!=2){
        cout<<"전체보기를 원하실 경우 1, 장르별 조회를 하실 경우 2를 입력해주세요: ";
        cin>>choice;

        if(choice==1){
            full(watch);    
        }
        else if(choice==2){
            category(watch);
        }
    }

}*/
//-------------------------------------------------
int main(){
    //movie watch[21];
    choice();
    //setting(watch);
    //choice2(watch);
}