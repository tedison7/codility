// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

int solution(int N, int M) {
    // write your code in C++14 (g++ 6.2.0)

    if (M == 1)
        return N;

    int result = 0;
    vector<bool> exist(N, true);
    int current = 0;
    while (true)
    {
        if (exist[current] == false)
        {
            break;
        }

        exist[current] = false;
        result++;
        current += M;
        if (current > N - 1)
        {
            current %= N;
        }
    }

    return result;
}

//https://app.codility.com/demo/results/training2MQ4WY-CQ9/


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int Calgcd(int a, int b)   //b가 큰수
{
    if (a == 0)
        return b;
    return Calgcd(b % a, a);
}

int solution(int N, int M) {
    // write your code in C++14 (g++ 6.2.0)

    if (M == 1)
        return N;

    int result = 0;
    int gcd = 0;
    if (N > M)
        gcd = Calgcd(M, N);
    else
        gcd = Calgcd(N, M);

    result = N / gcd;


    return result;
}

//https://app.codility.com/demo/results/trainingW69SSH-KZX/
