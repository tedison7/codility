// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

vector<int> solution(int N, vector<int>& P, vector<int>& Q) {
    // write your code in C++14 (g++ 6.2.0)

    //소수 구하기
    vector<int> primeArr(N + 1, 0);
    for (int i = 2; i * i <= N; i++)
    {
        if (primeArr[i] == 0)
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (primeArr[j] == 0)
                    primeArr[j] = i;
            }
        }
    }

    //반소수의 갯수 구하기
    vector<int> semiCount(N + 1, 0);
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (primeArr[i] != 0)
        {
            int j = i / primeArr[i];
            if (primeArr[j] == 0)
            {
                count++;
            }
        }
        semiCount[i] = count;
    }

    //반소수의 갯수
    int size = (int)P.size();
    vector<int> result(size, 0);
    for (int j = 0; j < size; j++)
    {
        result[j] = semiCount[Q[j]] - semiCount[P[j] - 1];
    }

    return result;
}

//https://app.codility.com/demo/results/trainingQFKZ6X-64J/