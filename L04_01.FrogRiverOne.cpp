// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

int solution(int X, vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    int result = -1;
    bool* leaves = new bool[A.size()]{ false, };
    int leaveCount = 0;

    for (unsigned int i = 0; i < A.size(); i++)
    {
        if (!leaves[A[i] - 1])
        {
            leaves[A[i] - 1] = true;
            leaveCount++;
            if (leaveCount == X)
            {
                result = i;
                break;
            }
        }
    }
    return result;
}

/*
Tasks Details
Easy
1. FrogRiverOne
Find the earliest time when a frog can jump to the other side of a river.
Task Score
100 %
Correctness
100 %
Performance
100 %
*/