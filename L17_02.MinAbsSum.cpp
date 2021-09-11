// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    int N = (int)A.size();
    int max = 0;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        A[i] = abs(A[i]);
        if (max < A[i])
            max = A[i];
        sum += A[i];
    }
    vector<int> count(max + 1, 0);
    for (int i = 0; i < max; i++)
    {
        count[A[i]]++;
    }

    vector<int> sList(sum + 1, -1);

    for (int i = 1; i < max + 1; i++)
    {
        if (count[i] > 0)
        {
            for (int j = 0; j < sum / 2 + 1; j++)
            {
                if (sList[j] >= 0)
                {
                    sList[j] = count[i];
                }
                else if (j >= i && sList[j - i] > 0)
                {
                    sList[j] = sList[j - i] - 1;
                }
            }
        }
    }

    cout << sum << " ///" << endl;
    for (int i = 0; i < sum / 2 + 1; i++)
    {
        cout << sList[i] << " ";
    }
    cout << endl;

    int result = sum;
    for (int i = 0; i < sum / 2 + 1; i++)
    {
        if (sList[i] >= 0)
        {
            result = min(result, sum - (2 * i));
        }
    }

    return result;
}