#include<bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int>
using namespace std;

void display(vvi nums){
	for(auto vec: nums){
		for(auto el: vec){
			cout << el << " ";
		}
		cout << endl;
	}
	cout<<endl;
}


void waveTraversal(vvi nums){
	
	// { 3 10 }
	// { 4 5 }	
	int rows = nums.size(); // 2
	int cols = nums[0].size(); // 2
	
	for(int j=0; j<cols; j++){
		
		if(j % 2 == 0){
			for(int i=0; i<rows; i++){
				cout << nums[i][j] << endl;
			}	
		}
		else{
		
			for(int i = rows - 1; i>=0; i--){
				cout << nums[i][j]<<endl;
			}	
		}
		
		
	}
}



int main(){
	int n,m;
	cin >> n >> m;
	
	vvi nums(n,vi(m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> nums[i][j];
		}
	}
	waveTraversal(nums);
	
	
}
