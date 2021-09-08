// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();
    vector<int> fib(27, 0);
    fib[1] = 1;
    for (int i = 2; i < 27; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    vector<int> reachable(N, -1);
    for (int i = 0; i < 27; i++)
    {
        if (fib[i] - 1 < N && A[fib[i] - 1] == 1)
        {
            reachable[fib[i] - 1] = 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (A[i] == 1 && reachable[i] < 0)
        {
            int min = N + 1;
            int minIdx = -1;
            for (int j = 0; j < 27; j++)
            {
                int pre = i - fib[j];
                if (pre < 0 || reachable[pre] < 0)
                    continue;

                if (min > reachable[pre])
                {
                    min = reachable[pre];
                    minIdx = pre;
                }
            }
            if (minIdx != -1)
                reachable[i] = min + 1;
        }
    }
    int result = -1;
    for (int i = 0; i < N; i++)
    {
        if (reachable[i] != -1)
        {
            if (result == -1)
                result = 0;

            result += reachable[i];
        }
    }
    return result;
}