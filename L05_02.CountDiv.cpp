// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int result = 0;
    for (int i = A; i < B; i++)
    {
        if (i % K == 0)
            result++;
    }

    return result;
}


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int result = 0;

    int aDiv = A / K;
    int bDiv = B / K;
    if (A % K != 0)
        aDiv++;

    result = bDiv - aDiv + 1;

    return result;
}

/*
Tasks Details
Medium
1. CountDiv
Compute number of integers divisible by k in range[a..b].
Task Score
100 %
Correctness
100 %
Performance
100 %
*/