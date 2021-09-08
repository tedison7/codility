// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <string>

using namespace std;

int GetFactor(char inChar)
{
    switch (inChar)
    {
    case 'A': return 1;
    case 'C': return 2;
    case 'G': return 3;
    case 'T': return 4;
    }
    return 0;
}

vector<int> solution(string& S, vector<int>& P, vector<int>& Q) {
    // write your code in C++14 (g++ 6.2.0)

    int N = (int)S.length();
    int M = (int)P.size();
    vector<int> result(M, 5);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int factor = GetFactor(S[i]);
            if (P[j] <= i && i <= Q[j] && result[j] > factor)
                result[j] = factor;
        }
    }

    return result;
}

/*
Tasks Details
Medium
1. GenomicRangeQuery
Find the minimal nucleotide from a range of sequence DNA.
Task Score
62%
Correctness
100%
Performance
0%
*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <string>

using namespace std;

vector<int> solution(string& S, vector<int>& P, vector<int>& Q) {
    // write your code in C++14 (g++ 6.2.0)

    int N = (int)S.length();
    int M = (int)P.size();
    vector<int> result(M, 4);
    int* A = new int[N + 1]{ 0, };
    int* C = new int[N + 1]{ 0, };
    int* G = new int[N + 1]{ 0, };

    for (int i = 0; i < N; i++)
    {
        switch (S[i])
        {
        case 'A': A[i + 1]++; break;
        case 'C': C[i + 1]++; break;
        case 'G': G[i + 1]++; break;
        }
        A[i + 1] += A[i];
        C[i + 1] += C[i];
        G[i + 1] += G[i];
    }

    for (int j = 0; j < M; j++)
    {
        if (P[j] == Q[j])
        {
            switch (S[P[j]])
            {
            case 'A': result[j] = 1; break;
            case 'C': result[j] = 2; break;
            case 'G': result[j] = 3; break;
            }
        }
        else
        {
            if (A[P[j]] < A[Q[j] + 1])
            {
                result[j] = 1;
            }
            else if (C[P[j]] < C[Q[j] + 1])
            {
                result[j] = 2;
            }
            else if (G[P[j]] < G[Q[j] + 1])
            {
                result[j] = 3;
            }
        }
    }

    return result;
}

/*
Tasks Details
Medium
1. GenomicRangeQuery
Find the minimal nucleotide from a range of sequence DNA.
Task Score
100 %
Correctness
100 %
Performance
100 %
*/