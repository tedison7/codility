// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();

    vector<int> sumList(N, 0);
    sumList[0] = A[0];
    int result = 0;
    for (int i = 1; i < N; i++)
    {
        sumList[i] = sumList[i - 1];
        for (int j = 2; j <= 6; j++)
        {
            if (i >= j)
            {
                sumList[i] = max(sumList[i], sumList[i - j]);
            }
            else
            {
                break;
            }
        }
        sumList[i] += A[i];
    }

    result = sumList[N - 1];

    return result;
}

//https://app.codility.com/demo/results/trainingGYRXZ7-AY4/