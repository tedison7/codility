// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

using namespace std;
vector<int> solution(int N, vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    vector<int> result(N, 0);
    int topCount = 0;
    int lastMaxCount = 0;
    for (unsigned int i = 0; i < A.size(); i++)
    {
        if (A[i] == N + 1)
        {
            lastMaxCount = topCount;
        }
        else
        {
            if (result[A[i] - 1] < lastMaxCount)
                result[A[i] - 1] = lastMaxCount + 1;
            else
                result[A[i] - 1]++;

            if (topCount < result[A[i] - 1])
                topCount = result[A[i] - 1];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (result[i] < lastMaxCount)
            result[i] = lastMaxCount;
    }

    return result;
}

/*
Tasks Details
Medium
1. MaxCounters
Calculate the values of counters after applying all alternating operations : increase counter by 1; set value of all counters to current maximum.
Task Score
100 %
Correctness
100 %
Performance
100 %
*/