// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <map>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    int N = (int)A.size();
    map<int, int> countMap;

    for (int i = 0; i < N; i++)
    {
        auto iter = countMap.find(A[i]);
        if (iter != countMap.end())
        {
            iter->second++;
        }
        else
        {
            countMap.insert({ A[i], 1 });
        }
    }
    int dominator = 0;
    int topCount = 0;
    for (auto& iter : countMap)
    {
        if (topCount < iter.second)
        {
            dominator = iter.first;
            topCount = iter.second;
        }
    }
    if (topCount * 2 <= N)
        return -1;

    for (int i = 0; i < N; i++)
    {
        if (dominator == A[i])
        {
            return i;
        }
    }

    return -1;
}