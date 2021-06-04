#include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[5] = {1, 2, 4, 5, 6};
    int size = sizeof(arr);
    int sizeOne = sizeof(arr[0]);
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << len << endl;
    cout << size << endl;
    cout << sizeOne << endl;
}