// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int result = 1;
    bool* exists = new bool[A.size()]{ false, };

    for (unsigned int i = 0; i < A.size(); i++)
    {
        if (A[i] > A.size() || exists[A[i] - 1] == true)
        {
            result = 0;
            break;
        }
        else
        {
            exists[A[i] - 1] = true;
        }
    }

    return result;
}

/*
Tasks Details
Easy
1. PermCheck
Check whether array A is a permutation.
Task Score
100 %
Correctness
100 %
Performance
100 %
*/