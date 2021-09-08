// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int CalGCD(int a, int b)
{
    if (b == 0)
        return a;
    return CalGCD(b, a % b);
}

bool SameDiv(int a, int b)
{
    if (a == b)
        return true;

    int gcd = CalGCD(a, b);
    int gcdA = 0;
    int gcdB = 0;

    while (gcdA != 1)
    {
        gcdA = CalGCD(a, gcd);
        a = a / gcdA;
    }
    while (gcdB != 1)
    {
        gcdB = CalGCD(b, gcd);
        b = b / gcdB;
    }

    return a == 1 && b == 1;
}

int solution(vector<int>& A, vector<int>& B) {
    // write your code in C++14 (g++ 6.2.0)

    int size = (int)A.size();

    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (SameDiv(A[i], B[i]))
            result++;
    }

    return result;
}

//https://app.codility.com/demo/results/trainingUX5TNA-B9Q/