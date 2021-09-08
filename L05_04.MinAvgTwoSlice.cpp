// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int result = 0;
    int N = (int)A.size();
    float minAvg = 0;
    float** avgList = new float* [N];

    for (int i = 0; i < N; i++)
    {
        avgList[i] = new float[N] {0, };
        float sum = (float)A[i];
        for (int j = i + 1; j < N; j++)
        {
            sum += (float)A[j];
            avgList[i][j] += sum;
            avgList[i][j] /= (float)(j - i + 1);
            if (i == 0 || minAvg > avgList[i][j])
            {
                minAvg = avgList[i][j];
                result = i;
            }
        }
    }
    return result;
}


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int result = 0;
    int N = (int)A.size();
    float minAvg = (float)(A[0] + A[1]) / 2.f;

    for (int i = 2; i < N; i++)
    {
        float avg = (float)(A[i - 2] + A[i - 1] + A[i]) / 3.f;
        if (avg < minAvg)
        {
            minAvg = avg;
            result = i - 2;
        }
        avg = (float)(A[i - 1] + A[i]) / 2.f;
        if (avg < minAvg)
        {
            minAvg = avg;
            result = i - 1;
        }
    }
    return result;
}
