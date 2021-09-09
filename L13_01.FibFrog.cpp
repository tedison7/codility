// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <queue>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    int N = (int)A.size();
    if (N == 0)
        return 1;

    vector<int> fib;
    fib.push_back(1); fib.push_back(1);

    for (int i = 2; fib[fib.size() - 1] <= N + 1; i++)
    {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
    queue<pair<int, int>> q;
    vector<bool> check(N + 1, false);
    q.push({ -1,0 });

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        for (int i = 0; i < (int)fib.size(); i++)
        {
            int next = current.first + fib[i];

            if (next == N)
            {
                return current.second + 1;
            }
            else if (next < N && next >= 0)
            {
                if (A[next] == 1 && !check[next])
                {
                    check[next] = true;
                    q.push({ next, current.second + 1 });
                }
            }
        }
    }
    return -1;
}

//https://app.codility.com/demo/results/training9P6W5S-NH9/