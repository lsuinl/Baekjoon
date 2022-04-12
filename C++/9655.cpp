#include <iostream>

using namespace std;

int main(){
    int stone;
    string a;
    cin>>stone;
    a=(stone%2==0)? "CY":"SK";
    cout<<a;
    return 0;
}