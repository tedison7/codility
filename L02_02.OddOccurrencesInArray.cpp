// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <set>

using namespace std;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    set<int> pairList;

    for (unsigned int i = 0; i < A.size(); i++)
    {
        auto iter = pairList.find(A[i]);
        if (iter != pairList.end())
        {
            pairList.erase(iter);
        }
        else
        {
            pairList.insert(A[i]);
        }
    }


    return pairList.size() > 0 ? *pairList.begin() : 0;
}

/*
Tasks Details
Easy
1. OddOccurrencesInArray
Find value that occurs in odd number of elements.
Task Score
77 %
Correctness
100 %
Performance
50 %
*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int result = 0;
    for (unsigned int i = 0; i < A.size(); i++)
    {
        result ^= A[i];
    }

    return result;
}

/*
Tasks Details
Easy
1. OddOccurrencesInArray
Find value that occurs in odd number of elements.
Task Score
100 %
Correctness
100 %
Performance
100 %
*/