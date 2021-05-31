#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#define len 10
using namespace std;

class MyArray
{
    int arr[len];

public:
    void create()
    {
        for (int i = 0; i < len; i++)
        {
            arr[i] = rand() % 20;
        }
    };

    void display()
    {
        for (int i = 0; i < len; i++)
        {
            cout << arr[i] << " ";
        }
    };

    void selectSort()
    {

        int min_element = 0;

        for (int i = 0; i < (len - 1); i++)
        {
            for (int j = i + 1; j < len; j++)
            {

                if (arr[j] < arr[i])
                {
                    min_element = arr[j];
                    arr[j] = arr[i];
                    arr[i] = min_element;
                }
            }
        }
    }
};

int main()
{

    MyArray arrObj;

    arrObj.create();
    cout << "Array before sorting: " << endl;
    arrObj.display();
    cout << endl;
    arrObj.selectSort();
    cout << "Array after sorting: " << endl;
    arrObj.display();
    return 0;
}