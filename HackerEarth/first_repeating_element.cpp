#include <iostream>
#include <cstdlib>
#include "bits/stdc++.h"

using namespace std;

int findNum(int a[], int size)
{
    const int N = 1e6 + 2;
    int idx[N];
    int minIdx = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }
    
}

int main()
{
    //length of array//
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int res = findNum(a[], n);
}