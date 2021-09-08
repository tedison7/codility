// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>

bool compare(int A, int B) { return A < B; }

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();

    int result = 0;
    sort(A.begin(), A.end(), compare);
    for (int i = 0; i < N - 2; i++)
    {
        if ((long long)A[i + 2] < (long long)A[i + 1] + (long long)A[i])
        {
            result = 1;
        }
    }
    return result;
}
