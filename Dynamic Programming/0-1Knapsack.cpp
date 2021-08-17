#include <bits/stdc++.h>
#define vi vector<int> 
#define vvi vector<vector<int>> 

/*
	Problem: Given a hashmap with key as weights and value as cost, determine the maximum weights which add up to maimum costs 
	in a bounded knapsack
	
	Intution: Make a DP 
	Compare values when you include the weights and when you dont. Take maximum of it. 
	
*/

using namespace std;


void knapsack(vi &costs, vi &nums, int m){
	
	
	int n = nums.size();
	
	vvi dp(n+1, vi(m+1, 0));
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			
			if(nums[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				
				// When you choose to play 

				
				int val = costs[i-1] + dp[i-1][j - nums[i-1]];
		
				// When you don't play // dp[i-1][j]
					
				dp[i][j] = max(val, dp[i-1][j]);
			}
		}
	}
	
	cout << dp[n][m] << endl;
	
	
	
}

int main(){
	
	int n; 
	cin >> n; 

	vi keys;
	vi costs;
	
	for(int i = 0; i<n; i++){
		int val;
		cin >> val;
		costs.push_back(val);
	}
	
	for(int k = 0; k<n; k++){
		int key; 
		cin >> key; 
		keys.push_back(key);
	}
	


	
	int cap; 
	cin >> cap;
	
	knapsack(costs,keys,cap);
}
