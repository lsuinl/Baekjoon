#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[1001], N;

int DP()
{
    int dpleft[1001] = {0,};
    for (int i = 0; i < N; ++i)
    {
        int a = arr[i];
        for (int j = 0; j < i; ++j)
            if (a > arr[j])
                dpleft[i] = max(dpleft[i], dpleft[j] + 1);
    }

    int dpright[1001] = {0,};
    for (int i = N - 1; i >= 0; --i)
    {
        int a = arr[i];
        for (int j = N - 1; j > i; --j)
            if (a > arr[j])
                dpright[i] = max(dpright[i], dpright[j] + 1);
    }

    int result = 0;
    for (int i = 0; i < N; i++)
        result = max(result, (dpright[i] + dpleft[i]));
    return result + 1;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << DP();

    return 0;
}