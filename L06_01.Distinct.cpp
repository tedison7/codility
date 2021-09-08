// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <set>
#include <hash_set>


int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    __gnu_cxx::hash_set<int> distinct;
    for (int i = 0; i < (int)A.size(); i++)
    {
        if (distinct.find(A[i]) == distinct.end())
        {
            distinct.insert(A[i]);
        }
    }
    return (int)distinct.size();
}

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <algorithm>

bool compare(int a, int b) { return a < b; }

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();
    if (N == 0)
        return 0;

    sort(A.begin(), A.end(), compare);


    int result = 1;
    for (int i = 0; i < (int)A.size() - 1; i++)
    {
        if (A[i] != A[i + 1])
            result++;
    }

    return result;
}
