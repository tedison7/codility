// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <algorithm>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    int N = (int)A.size();
    if (N < 3)
        return 0;

    vector<int> sorted(N, 0);
    for (int i = 0; i < N; i++)
        sorted[i] = A[i];

    sort(sorted.begin(), sorted.end());

    if (sorted[0] == sorted[N - 1])
    {
        //N_C_6
        return N * (N - 1) * (N - 2) / 6;
    }

    int result = 0;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if (sorted[k] >= sorted[j] + sorted[i])
                    break;
                result++;
            }
        }
    }
    return result;
}

//https://app.codility.com/demo/results/trainingZ574G4-WCT/