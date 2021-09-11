// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    int N = (int)A.size();

    int sum = 0;
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (sum >= K)
        {
            result++;
            sum = 0;
        }
    }
    return result;
}

//https://app.codility.com/demo/results/trainingK7FH49-YY3/