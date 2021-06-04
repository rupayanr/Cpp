#include <bits/stdc++.h>
using namespace std;


void display(int *arr, int n){
	
	for (int j=0; j<n; j++){
		cout << arr[j] << " ";
	}
}


void display_vec(vector<int> &v){
	
	for(auto i: v){
		cout << i << " ";
	}
}


int main(){
	
	string str="";
	int n;
	cin>>n;
	
	int arr[n];
	vector<int> v;
	
	for(int i=0; i< n; i++){
		cin >> arr[i];
	}
	
	for(int i=0; i< n; i++ ){
		
		v.push_back(arr[i] % 10);
	}
	
	for(int i=0; i<n;i++){
		
		str += to_string(v[i]);
		
	}
	
	
	int res = stoi(str) % 10;
	if(res){
		cout << "No";
		
	}
	else{
		cout << "Yes";
	}
	
}
