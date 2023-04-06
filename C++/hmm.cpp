
#include <string>
#include <vector>

using namespace std;
//총합
//타겟을 위해 빼야하는 숫자.

//빼야하는 숫자를 만드는 조합(중복포함)

int solution(vector<int> numbers, int target) {
    
    int answer = 0;
    int sum=0;
    for(int i=0;i<numbers.size();i++){
        sum+=numbers[i];
    }
    sum-=target;
    void plus(int suin,int index){
        suin+=numbers[index];
        if(sum<suin){return;}
        else if(sum==suin){answer++; return;}
        else{ plus(suin,index+1); }
    }
    for(int i=0;i<numbers.size();i++) plus(numbers[i],0);
    
    return answer;
}
