#include <iostream>
#include <vector>
#include <string>

using namespace std;


int solution(vector<int> ingredient) {
    int answer = 0;
        for(int i=0;i<ingredient.size();i++){
        if(ingredient[i]==1 && ingredient[i+1]==2 &&ingredient[i+2]==3 && ingredient[i+3]==1){
            ingredient.erase(ingredient.begin()+i);
            ingredient.erase(ingredient.begin()+i);
            ingredient.erase(ingredient.begin()+i);
            ingredient.erase(ingredient.begin()+i);
            answer++;
            i= (i-3)>0?i-3:-1;
        }
    }
    return answer;
}

int main(){
    vector<int> ingredient ={2, 1, 1, 2, 3, 1, 2, 3, 1};
    cout<<solution(ingredient);
    return 0;
}