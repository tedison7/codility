// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <stack>

int solution(vector<int>& H) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)H.size();
    int result = 0;
    stack<int> sBlock;
    for (int i = 0; i < N; i++)
    {
        if (sBlock.empty())
        {
            sBlock.push(H[i]);
        }
        else if (sBlock.top() < H[i])
        {
            sBlock.push(H[i]);
        }
        else if (sBlock.top() > H[i])
        {
            while (!sBlock.empty() && sBlock.top() > H[i])
            {
                sBlock.pop();
                result++;
            }
            if (sBlock.empty() || sBlock.top() != H[i])
            {
                sBlock.push(H[i]);
            }
        }
    }
    result += (int)sBlock.size();

    return result;
}
