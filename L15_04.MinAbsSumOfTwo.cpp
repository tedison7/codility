// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <map>
#include <algorithm>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();

    map<int, int> aMap;
    for (int i = 0; i < N; i++)
    {
        aMap.insert({ A[i], 2000000001 });
    }

    int result = 2000000001;
    for (int i = 0; i < N; i++)
    {
        for (auto& iter : aMap)
        {
            if (abs(iter.first + A[i]) < iter.second)
            {
                iter.second = abs(iter.first + A[i]);
                result = min(iter.second, result);
            }
        }
    }
    return result;
}

//https://app.codility.com/demo/results/trainingHYGDW8-DUR/



// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    int N = (int)A.size();

    sort(A.begin(), A.end());

    int left = 0;
    int right = N - 1;
    int result = 2000000001;

    while (left < right)
    {
        int absSum = abs(A[left] + A[right]);
        if (absSum < result)
            result = absSum;

        if (abs(A[left]) > abs(A[right]))
            left++;
        else
            right--;
    }

    int absSum = abs(A[left] + A[right]);
    if (absSum < result)
        result = absSum;

    return result;
}

//https://app.codility.com/demo/results/trainingSK8GYC-RPS/