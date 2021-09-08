// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>

bool compare(int a, int b) { return a < b; }

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    int N = (int)A.size();
    sort(A.begin(), A.end(), compare);

    int result = A[N - 1] * A[N - 2] * A[N - 3];

    if (result < A[0] * A[1] * A[N - 1])
        result = A[0] * A[1] * A[N - 1];

    return result;
}
