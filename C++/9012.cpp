#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    string line;
    
    for(int i=0;i<n;i++){
        cin>>line;
        int left=0, right=0;
        for(int j=0;j<line.length();j++){
           if(line[j]=='(')
                left++;
            else
                right++;
            
            if(line[j]==')' && right>left){
                left=50;
                break;
            }
        }
        if(left!=right)
            cout<<"NO";
        else
            cout<<"YES";
    }
    return 0;
    
}