// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    int finalBinaryGap = 0;
    int binaryGap = 0;
    bool bGapStart = false;

    while (N > 1)
    {
        if (N % 2 == 1)
        {
            if (!bGapStart)
                bGapStart = true;

            if (finalBinaryGap < binaryGap)
                finalBinaryGap = binaryGap;

            binaryGap = 0;
        }
        else
        {
            if (bGapStart)
                binaryGap++;
        }
        N /= 2;
    }
    if (bGapStart)
    {
        if (finalBinaryGap < binaryGap)
            finalBinaryGap = binaryGap;
    }

    return finalBinaryGap;
}

/*
Tasks Details
Easy
1. BinaryGap
Find longest sequence of zeros in binary representation of an integer.
Task Score
100 %
Correctness
100 %
Performance
Not assessed
*/