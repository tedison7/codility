// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <map>
#include <vector>

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    if (N == 1)
        return 4;

    //소인수 분해
    map<int, int> factorCount;
    vector<int> factors;
    factors.push_back(1);


    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            factors.push_back(i);
        }
    }

    int result = 0;
    int perimeter = 0;
    for (unsigned int i = 0; i < factors.size(); i++)
    {
        perimeter = (factors[i] * 2) + (N / factors[i] * 2);
        if (i == 0 || result > perimeter)
            result = perimeter;
    }

    return result;
}

//https://app.codility.com/demo/results/trainingVNBB9Z-CB2/