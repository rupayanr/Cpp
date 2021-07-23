#include <bits/stdc++.h>

using namespace std;


void rotate(int *arr, int n, int k){
	
	
	if(k < 0){
		k = k+n;
	}
	
	while(k >= n){
		k = k % n;
	}
	
	vector<int> rot(n);
	
	for(int i=0; i<n; i++){
		rot[(i+k) % n] = arr[i];
	}
	
	for(int i=0; i<n; i++){
		arr[i] = rot[i];
	}
}

void display(int *arr, int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
		
	int n;
	cin >> n;
	
	int *arr = new int[n];
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int k;
	cin >>k;
	
	rotate(arr,n,k);
	display(arr,n);
}
