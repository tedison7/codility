// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();

    vector<int> count((N * 2) + 1, 0);

    for (int i = 0; i < N; i++)
    {
        count[A[i]]++;
    }

    //약수의 갯수를 구해서 전체에서 뺴자.
    vector<int> result(N, 0);
    for (int i = 0; i < N; i++)
    {
        int divisors = 0;
        for (int j = 1; j * j <= A[i]; j++)
        {
            if (A[i] % j == 0)
            {
                divisors += count[j];

                if (A[i] / j != j)
                {
                    divisors += count[A[i] / j];
                }
            }
        }
        result[i] = N - divisors;
    }

    return result;
}

//https://app.codility.com/demo/results/trainingHQMS5P-9D8/