// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <stack>

int solution(string& S) {
    // write your code in C++14 (g++ 6.2.0)
    int N = S.length();

    if (N % 2 == 1)
        return 0;

    stack<int> charStack;

    for (int i = 0; i < N; i++)
    {
        if (S[i] == '(')
        {
            charStack.push(1);
        }
        else
        {
            if (charStack.size() == 0)
                return 0;
            else
                charStack.pop();
        }
    }

    return charStack.size() == 0 ? 1 : 0;
}