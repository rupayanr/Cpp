#include<bits/stdc++.h>
using namespace std;




int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    // { 10 20 30 40 }
    for(int i=0; i<n; i++){
    	
        for(int j=i; j<n; j++){
			
			for(int k=i; k<=j; k++){
				cout << arr[k] << " "; // 10 
			}
			cout << endl;
        }
    }
}
