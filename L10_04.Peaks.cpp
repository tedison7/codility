// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <cmath>
#include <algorithm>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();
    if (N < 3)
        return 0;

    vector<int> peaks;
    for (int i = 1; i < N - 1; i++)
    {
        if (A[i] > A[i - 1] && A[i] > A[i + 1])
        {
            peaks.push_back(i);
        }
    }
    int peakCount = (int)peaks.size();

    if (peakCount < 3)
        return peakCount;

    int result = 0;
    for (int i = 1; i <= peakCount; i++)
    {
        if (N % i == 0)
        {
            int block = N / i;
            int current = 0;
            for (int j = 0; j < peakCount; j++)
            {
                if (current * block <= peaks[j] && peaks[j] < (current + 1) * block)
                {
                    current++;
                }
            }
            if (current == i)
            {
                result = current;
            }
        }
    }

    return result;
}

//https://app.codility.com/demo/results/trainingNKQKB3-USZ/