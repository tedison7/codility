// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <set>
#include <algorithm>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();

    set<int> list;
    for (int i = 0; i < N; i++)
    {
        int AddNum = abs(A[i]);
        if (list.find(AddNum) == list.end())
        {
            list.insert(AddNum);
        }
    }

    return (int)list.size();
}

//https://app.codility.com/demo/results/trainingE3C32M-BM3/