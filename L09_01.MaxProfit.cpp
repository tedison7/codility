// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();
    int topProfit = 0;
    int lowestPrice = 200001;

    for (int i = 0; i < N; i++)
    {
        if (lowestPrice > A[i])
        {
            lowestPrice = A[i];
        }
        else if (topProfit < A[i] - lowestPrice)
        {
            topProfit = A[i] - lowestPrice;
        }
    }
    return topProfit;
}
