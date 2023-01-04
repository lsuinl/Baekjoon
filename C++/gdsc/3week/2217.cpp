#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> q; // 오름차순으로 정렬하는 큐(우선순위 큐)
    int N, result = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int rope;
        cin >> rope;
        q.push(rope);
    }
    result = q.top() * N;
    for (int i = 1; i < N; i++)
    {
        q.pop();
        result = q.top() * (N - i) > result ? q.top() * (N - i) : result;
    }
    cout << result << "\n";

    return 0;
}