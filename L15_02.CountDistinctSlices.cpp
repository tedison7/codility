// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <unordered_map>
#include <set>

int solution(int M, vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();

    long long result = 0;
    unordered_map<int, int> uList;
    int left = 0;
    int right = 0;

    while (right < N)
    {
        auto iter = uList.find(A[right]);
        if (iter == uList.end() || iter->second < left)
        {
            uList[A[right]] = right;
            right++;
        }
        else
        {
            result += (long long)(right - left) * (long long)(right - left + 1) / 2;
            long long r = right - iter->second - 1;
            result -= r * (r + 1) / 2;
            left = iter->second + 1;

            if (result > 1000000000)
                return 1000000000;
        }
    }
    result += (long long)(right - left) * (long long)(right - left + 1) / 2;

    if (result > 1000000000)
        return 1000000000;
    return result;

}

//https://app.codility.com/demo/results/trainingSZURGM-6Z8/