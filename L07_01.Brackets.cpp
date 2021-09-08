// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <string>
#include <stack>

int solution(string& S) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)S.length();

    stack<int> stk;

    for (int i = 0; i < N; i++)
    {
        switch (S[i])
        {
        case '{': stk.push(1); break;
        case '[': stk.push(2); break;
        case '(': stk.push(3); break;
        case '}':
        {
            if (stk.top() == 1)
                stk.pop();
            else
                return 0;
        }
        break;
        case ']':
        {
            if (stk.top() == 2)
                stk.pop();
            else
                return 0;
        }
        break;
        case ')':
        {
            if (stk.top() == 3)
                stk.pop();
            else
                return 0;
        }
        break;
        }
    }

    if (stk.size() > 0)
        return 0;

    return 1;
}