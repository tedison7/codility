// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>

using namespace std;

int solution(int K, int M, vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();

    int totalsum = 0;
    for (int i = 0; i < N; i++)
        totalsum += A[i];

    if (K == 1)
        return totalsum;

    int low = 0;
    int high = totalsum;
    int result = totalsum;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sum = 0;
        int maxSum = 0;
        int groupCount = 1;

        for (int i = 0; i < N; i++)
        {
            if (sum + A[i] > mid)
            {
                maxSum = max(sum, maxSum);
                sum = A[i];
                groupCount++;
            }
            else
            {
                sum += A[i];
            }
        }
        maxSum = max(sum, maxSum);
        if (groupCount > K)
        {
            low = mid + 1;
        }
        else
        {
            result = min(maxSum, result);
            high = mid - 1;
        }
    }
    return result;
}

//https://app.codility.com/demo/results/trainingCGRDAY-VTA/