#include <iostream>

int getMaxValue_60211905(){
    int first, second;
    std::cout<<"첫번째 수를 입력해주세요: ";
    std::cin>>first;
    std::cout<<"두번째 수를 입력해주세요: ";
    std::cin>>second;
    if(first>second)
        return first;
    else
        return second;
}

int main()
{
    int maxValue;
    maxValue=getMaxValue_60211905();
    std::cout<<"큰 수: ";
    std::cout<<maxValue;
}