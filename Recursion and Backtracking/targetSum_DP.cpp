#include <bits/stdc++.h>
using namespace std;

// Construct a func that takes in a targetSum and an array 
//if any subset of the array is able to make that target using add or as is return true

bool targetSum(int sum, vector<int> nums){
	
	// Idea is to create a 2D matrix which holds boolean values 
	// The values at dp[i][j] corresponds to weather a[i-1] can make the targetSum or not
	// Each val can either be involved or not involved 
	// If val is involved then we have to check dp[i-1][j - val] 
	
	int n = nums.size();
	bool dp[n+1][sum+1]; 
	
	for(int i=0; i < n+1; i++){
		for(int j = 0; j < sum+1; j++){
			
			if(i == 0 && j==0){
				dp[i][j] == true;
			}
			else if(i == 0){
				dp[i][j] == false;
			}
			else if(j == 0){
				dp[i][j] == true;
			}
			else{
				
				if(dp[i-1][j] == true){
					dp[i][j] = true;
				}
				else{
					int val = nums[i-1];
					
					if(j >= val){
						if(dp[i-1][j - val] == true){
							dp[i][j] == true;
						}
					}
				}
				
				
			}
			
		}
	}
	
	return dp[n][sum];
	
}


int main(){
	
	
	vector<int> nums = {4, 3, 2, 1};
	if(targetSum(5,nums)){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
}
