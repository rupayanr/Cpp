#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void reverseArray(int arr[], int start,int end){

    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

}

void printArray(int arr[],int size){
    
    for(int i=0; i < size; i++){
        cout << arr[i] << " ";
    }
    
}


int main(){
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // Taking input to form an array //

    // First we need sizeofarray 
    int sizeofarr;
    cout << "Enter Size Of Array: ";
    cin >> sizeofarr;
    int nums[sizeofarr];
    
    // Enter array elements
    cout << "Enter array elements: ";
    for(int i=0; i < sizeofarr; i++){

        cin >> nums[i];
    } 

    // Displyaing array elements
    cout << "Array of Numbers to be reversed: " << "\n";
    for(int i=0; i < sizeofarr; i++){

        cout << nums[i] << "\n";
    }

    // Calling reverse array function 
    reverseArray(nums,0,sizeofarr - 1);
    printArray(nums,sizeofarr);
    

    return 0;
}
