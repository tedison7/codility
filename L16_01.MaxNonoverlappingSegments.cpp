// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

int solution(vector<int>& A, vector<int>& B) {
    // write your code in C++14 (g++ 6.2.0)

    int N = (int)A.size();
    if (N == 0)
        return 0;

    int result = 1;
    int right = B[0];
    for (int i = 1; i < N; i++)
    {
        if (A[i] > right)
        {
            result++;
            right = B[i];
        }
    }
    return result;
}

//https://app.codility.com/demo/results/trainingJEP49Y-H5H/

