// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <set>
using namespace std;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    int result = 1;
    set<int> Exist;
    for (unsigned int i = 0; i < A.size(); i++)
    {
        if (A[i] > 0)
        {
            if (Exist.find(A[i]) == Exist.end())
            {
                Exist.insert(A[i]);
            }
        }
    }

    int prevInt = 0;
    bool bFind = false;
    for (auto iter = Exist.begin(); iter != Exist.end(); iter++)
    {
        if (prevInt + 1 == *iter)
            prevInt++;
        else
        {
            result = prevInt + 1;
            bFind = true;
            break;
        }
    }
    if (bFind == false)
        result = prevInt + 1;

    return result;
}

/*
Tasks Details
Medium
1. MissingInteger
Find the smallest positive integer that does not occur in a given sequence.
Task Score
100 %
Correctness
100 %
Performance
100 %
*/