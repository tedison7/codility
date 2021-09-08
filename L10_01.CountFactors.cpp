// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <map>

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    //소인수 분해
    int div = 2;
    map<int, int> factorCount;

    int result = 1;
    if (N > 1)
    {
        while (N > 1)
        {
            if (N % div == 0)
            {
                auto iter = factorCount.find(div);
                if (iter != factorCount.end())
                    iter->second++;
                else
                    factorCount.insert({ div, 1 });
                N /= div;
            }
            else
            {
                div++;
            }
        }
    }
    for (auto& iter : factorCount)
    {
        result *= (iter.second + 1);
    }

    return result;
}

//https://app.codility.com/demo/results/trainingUQ5TKE-CNJ/


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <map>
#include <cmath>

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    if (N == 1)
        return 1;

    //약수의 갯수

    int count = 1;

    for (int i = 2; i < sqrt(N); i++)
    {
        if (N % i == 0)
            count++;
    }

    count *= 2;
    if (sqrt(N) / 1.00 == (int)sqrt(N))
        count++;

    return count;
}

//https://app.codility.com/demo/results/trainingC2QNC8-HQ5/