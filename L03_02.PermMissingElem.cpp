// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    long long vecSize = (long long)A.size() + 1;
    long long totalsum = vecSize * (vecSize + 1) / 2;
    for (unsigned int i = 0; i < A.size(); i++)
    {
        totalsum -= (long long)A[i];
    }
    return (int)totalsum;
}

/*
Tasks Details
Easy
1. PermMissingElem
Find the missing element in a given permutation.
Task Score
100 %
Correctness
100 %
Performance
100 %
*/