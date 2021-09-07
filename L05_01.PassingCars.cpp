// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    int result = 0;
    int leftCount = 0;

    for (unsigned int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
            leftCount++;
        else
        {
            result += leftCount;
            if (result > 1000000000)
            {
                result = -1;
                break;
            }
        };
    }
    return result;
}

/*
Tasks Details
Easy
1. PassingCars
Count the number of passing cars on the road.
Task Score
100 %
Correctness
100 %
Performance
100 %
*/