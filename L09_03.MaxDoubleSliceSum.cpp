// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <cmath>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    int N = (int)A.size();

    if (N == 3)
        return 0;

    int result = 0;
    vector<int> leftSum(N);
    vector<int> rightSum(N);

    for (int i = 1; i < N - 1; i++)
    {
        leftSum[i] = max(leftSum[i - 1] + A[i], 0);
    }
    for (int i = N - 2; i >= 1; i--)
    {
        rightSum[i] = max(rightSum[i + 1] + A[i], 0);
    }
    for (int i = 1; i < N - 1; i++)
    {
        result = max(result, leftSum[i - 1] + rightSum[i + 1]);
    }

    return result;
}

//https://app.codility.com/demo/results/trainingHPM535-B8X/
