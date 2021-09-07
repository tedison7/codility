// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    int result = 0;
    int distance = Y - X;
    result = (distance / D);
    if (distance % D > 0)
        result += 1;
    return result;
}

/*
Tasks Details
Easy
1. FrogJmp
Count minimal number of jumps from position X to Y.
Task Score
100 %
Correctness
100 %
Performance
100 %
*/