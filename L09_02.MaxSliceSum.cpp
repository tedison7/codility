// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>


//카데인 알고리즘
int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    int N = (int)A.size();
    long long maxSum = A[0];
    long long sum = A[0];

    for (int i = 1; i < N; i++)
    {
        if (sum + A[i] > A[i])
        {
            sum = sum + A[i];
        }
        else
        {
            sum = A[i];
        }
        if (maxSum < sum)
            maxSum = sum;
    }

    return maxSum;
}

//https://app.codility.com/demo/results/trainingR78FZE-6RE/