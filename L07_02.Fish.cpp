// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <stack>

int solution(vector<int>& A, vector<int>& B) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();
    stack<int> downStack;

    int result = 0;

    for (int i = 0; i < N; i++)
    {
        if (B[i] == 0)
        {
            while (downStack.size() > 0)
            {
                if (downStack.top() < A[i])
                    downStack.pop();
                else
                    break;
            }

            if (downStack.size() == 0)
                result++;
        }
        else
        {
            downStack.push(A[i]);
        }
    }
    result += downStack.size();
    return result;
}