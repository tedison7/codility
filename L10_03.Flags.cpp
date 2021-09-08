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
    for (int i = 2; i <= peakCount; i++)
    {
        int flag = 1;
        int peak = 0;
        int nextPeak = 1;
        while (peak < peakCount - 1)
        {
            if (peaks[nextPeak] - peaks[peak] >= i)
            {
                flag++;
                peak = nextPeak;
                nextPeak++;
            }
            else
            {
                nextPeak++;
            }

            if (nextPeak == peakCount || flag == i)
                break;
        }
        if (result > flag)
            return result;
        if (flag > result)
            result = flag;
    }
    return result;
}

//https://app.codility.com/demo/results/trainingEHSXAV-YTB/