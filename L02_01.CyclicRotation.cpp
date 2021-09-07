// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

using namespace std;

vector<int> solution(vector<int>& A, int K) {
    // write your code in C++14 (g++ 6.2.0)

    vector<int> vecSolution;
    int vecSize = A.size();
    if (vecSize > 0)
    {
        int startPos = vecSize - (K % vecSize);
        for (int i = 0; i < vecSize; i++)
        {
            int AddPos = (startPos + i) % vecSize;
            vecSolution.push_back(A[AddPos]);
        }
    }

    return vecSolution;
}

/*
Tasks Details
Easy
1. CyclicRotation
Rotate an array to the right by a given number of steps.
Task Score
100 %
Correctness
100 %
Performance
Not assessed
*/