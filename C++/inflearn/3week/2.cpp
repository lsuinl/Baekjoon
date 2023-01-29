#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, min[101], result = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> min[i];
    }
    sort(min, min + n);
    if (n % 2 == 0)
    {
        for(int i=1;i<n-2;i+=2){
            result+=min[0]+min[n-i]+(min[1]*2);
        }
        result+=min[1];
    }
    else{
        for(int i=1;i<n-2;i+=2){
            result+=min[0]+min[n-i]+(min[1]*2);
        }
        result+=min[0]+min[1]+min[2];
    }
    cout<<result;

    return 0;
}