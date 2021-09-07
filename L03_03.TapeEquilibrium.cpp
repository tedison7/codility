// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <cmath>

using namespace std;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int totalSum = 0;
    int result = -1;

    for (unsigned int i = 0; i < A.size(); i++)
        totalSum += A[i];

    int localSum = 0;
    int gap = 0;
    for (unsigned int i = 0; i < A.size() - 1; i++)
    {
        localSum += A[i];
        gap = abs(totalSum - (localSum * 2));

        if (result == -1 || gap < result)
            result = gap;
    }

    return result;
}

/*
Tasks Details
Easy
1. TapeEquilibrium
Minimize the value | (A[0] + ... + A[P - 1]) - (A[P] + ... + A[N - 1]) | .
Task Score
100 %
Correctness
100 %
Performance
100 %
*/