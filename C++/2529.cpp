#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool check(char arr[],int number[], int n){
        bool check = true;
        for (int i = 0; i <n; i++)
        {
            if (arr[i] == '>' && (number[i] < number[i + 1]))
            {
                check = false;
                break;
            }
            else if (arr[i] == '<' && (number[i] > number[i + 1]))
            {
                check = false;
                break;
            }
        }
        return check;
}

int main()
{
    int n;
    long max = 0, min = 9999999999;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    int number[n + 1];
    for (int i = 0; i < (n + 1); i++) //최댓값 배열
        number[i] = 9 - i;

    sort(number, number + (n + 1));
    do
    {
        if (check(arr,number,n))
        {
            long answer = 0;
            for (int i = 0; i < (n + 1); i++)
            {
                answer += number[i] * pow(10, n - i);
            }
            if (answer > max)
                max = answer;
        }
    } while (next_permutation(number, number + (n + 1)));

    for (int i = 0; i < (n + 1); i++) //최솟값 배열
        number[i] = i;
    do
    {
        if (check(arr,number,n))
        {
            long answer = 0;
            for (int i = 0; i < (n + 1); i++)
            {
                answer += number[i] * pow(10, n - i);
            }
            if (answer < min)
                min = answer;
        }
    } while (next_permutation(number, number + (n + 1)));

    if(min<pow(10,n)) //출렼
        cout<<max<<"\n"<<0<<min;
    else
        cout<<max<<"\n"<<min;
}