// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <vector>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    int result = 0;
    int N = (int)A.size();
    vector<long long> left;
    vector<long long> right;
    for (int i = 0; i < N; i++)
    {
        left.push_back((long long)i - (long long)A[i]);
        right.push_back((long long)i + (long long)A[i]);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int j = 0;
    for (int i = 0; i < N; i++)
    {
        while (j < N && right[i] >= left[j])
        {
            result += j;
            result -= i;
            j++;
        }
    }
    if (result > 10000000)
        return -1;

    return result;
}