#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> blocks;
    int h, w;
    cin >> h >> w;
    blocks.resize(w);
    for (int i = 0; i < w; i++)
        cin >> blocks[i];

    vector<int> leftMax(w), rightMax(w);
    leftMax[0] = blocks[0];
    for (int i = 1; i < w; i++)
        leftMax[i] = max(leftMax[i - 1], blocks[i]);
    for (int i = w - 2; i >= 0; i++)
        rightMax[i] = max(rightMax[i + 1], blocks[i]);

    int result = 0;
    for (int i = 0; i < w; i++)
        result += min(leftMax[i], rightMax[i]) - blocks[i];
    cout << result;
    return 0;
}