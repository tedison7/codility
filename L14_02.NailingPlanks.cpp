// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

int solution(vector<int>& A, vector<int>& B, vector<int>& C) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();
    int M = (int)C.size();


    vector<bool> nailed(N, false);
    int nailedPlankCount = 0;

    int result = -1;
    for (int i = 0; i < M; i++)
    {
        int left = 0;
        int right = N - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (A[mid] <= C[i] && C[i] <= B[mid] && nailed[mid] == false)
            {
                nailed[mid] = true;
                nailedPlankCount++;
                if (A[mid] == C[i])
                {
                    right = mid - 1;
                }
                else if (B[mid] == C[i])
                {
                    left = mid + 1;
                }
                else
                {
                    break;
                }
            }
            else if (A[mid] > C[i] || (B[mid] > C[i] && nailed[mid] == true))
            {
                right = mid - 1;
            }
            else if (B[mid] < C[i] || (A[mid] < C[i] && nailed[mid] == true))
            {
                left = mid + 1;
            }
        }

        if (nailedPlankCount == N)
        {
            result = i + 1;
            break;
        }
    }

    return result;

}

//https://app.codility.com/demo/results/trainingT6YKPB-KTR/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <algorithm>

int findMinIndex(int A, int B, vector<pair<int, int>>& nailSort, int before)
{
    int min = 0;
    int max = (int)nailSort.size();
    int minIndex = -1;
    while (min <= max)
    {
        int mid = (min + max) / 2;
        if (nailSort[mid].first < A)
            min = mid + 1;
        else if (nailSort[mid].first > B)
            max = mid - 1;
        else
        {
            max = mid - 1;
            minIndex = mid;
        }
    }
    if (minIndex == -1)
        return -1;
    int index = nailSort[minIndex].second;
    for (int i = minIndex; i < (int)nailSort.size(); i++)
    {
        if (nailSort[i].first > B)
            break;
        index = std::min(index, nailSort[i].second);
        if (index <= before)
            return before;
    }
    return index;
}

int solution(vector<int>& A, vector<int>& B, vector<int>& C) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();
    int M = (int)C.size();

    vector<pair<int, int>> nailSort(M, { 0,0 });
    for (int i = 0; i < M; i++)
    {
        nailSort[i].first = C[i];
        nailSort[i].second = i;
    }

    sort(nailSort.begin(), nailSort.end());

    int result = -1;
    for (int i = 0; i < N; i++)
    {
        result = findMinIndex(A[i], B[i], nailSort, result);
        if (result == -1)
            return -1;
    }

    return result + 1;

}

//https://app.codility.com/demo/results/training7STUN8-FNS/