// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <cmath>
#include <vector>
#include <algorithm>

vector<int> solution(vector<int>& A, vector<int>& B) {
    // write your code in C++14 (g++ 6.2.0)

    int L = (int)A.size();
    int max = pow(2, 30);
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);
    for (int i = 2; i <= 50000; i++)
    {
        long long newfib = ((long long)fib[i - 1] + (long long)fib[i - 2]) % (long long)max;
        fib.push_back((int)newfib);
    }
    vector<int> result;
    for (int i = 0; i < L; i++)
    {
        result.push_back(fib[A[i]] % (int)pow(2, (B[i])));
    }
    return result;
}

//https://app.codility.com/demo/results/trainingH3XBH7-XG4/