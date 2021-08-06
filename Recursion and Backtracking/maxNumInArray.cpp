#include<bits/stdc++.h>
using namespace std; 

int maxNum(int arr[], int i, int n){
	
	// Base Case
	if(i == n-1){
		return arr[i];
	}
	
	
	int first = arr[i];
	int res = maxNum(arr, i+1, n);
	
	int maxNum = max(first,res);
	return maxNum;
	
	
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	
	int ans = maxNum(arr,0,n);
	cout << ans << endl;
}
