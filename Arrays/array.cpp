#include <iostream>
using namespace std;

int main()
{

    int arr[] = {4, 5, 6, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
}