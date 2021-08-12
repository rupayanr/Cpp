#include<bits/stdc++.h>
#define vi vector<int> 
#define vvi vector<vector<int>>

using namespace std; 

/*
	Problem: 
	Given a n*m matrix, each cell filled with gold costs 
	You are a gold digger (lmao that was your ex), you have to find the max amount you can amass
	while digging in these three directions 
	
	-> Right
	-> Right - up 
	-> Right - down 
	
	Solution: 
	Make a DP[n][m]
	
	Fill the DP from last col reducing rows one by one 
	
	// Fill last col first 
		dp[i][j] = gold[i][j]
	
	
	// Top Row (i == 0) 
		dp[i][j] = max(dp[i][j+1], dp[i+1][j+1]) + gold[i][j]
	
	// Bottom Row (i==n-1)
		dp[i][j] = max(dp[i][j+1], dp[i-1][j+1]) + gold[i][j]
		
	// Rest 
		dp[i][j] = max(dp[i][j+1], dp[i+1][j+1], dp[i-1][j+1]) + gold[i][j]	
		
		
*/
void display(vvi &mat){
	for(auto vec: mat){
		for(auto el: vec){
			cout << el << " ";
		}
		cout << endl;
	}
	
	cout << endl;
	cout << endl;
}


void goldDigger(vvi &gold){
	
	int n = gold.size();
	int m = gold[0].size();
	
	vvi dp(n,vi(m,0));
	
	// Fill the last col 
	for(int i=0, j=m-1; i<n; i++){
		
		dp[i][j] = gold[i][j];
	}
	
	for(int j=m-2; j>=0; j--){
		for(int i=0; i<n; i++){
			
			// Top Row 
			if(i == 0){
				dp[i][j] = max(dp[i][j+1], dp[i+1][j+1]) + gold[i][j];
			}
			else if(i == n-1){
				dp[i][j] = max(dp[i][j+1], dp[i-1][j+1]) + gold[i][j];
			}
			else{
			
				int dmax = max(dp[i][j+1], dp[i-1][j+1]);
				int omax = max(dmax,dp[i+1][j+1]); 
				
			
				dp[i][j] = max(dmax,dp[i+1][j+1]) + gold[i][j];
			}
			
		}
	}
	
	display(dp);
	
	int res = INT_MIN;
	for(int i=0, j=0; i<n; i++){
		res = max(res, dp[i][j]);
	}
	
	
	cout << res << endl;
}

int main(){
	int n, m;
	cin >> n >> m;
	
	vvi gold(n, vi(m,0));

	for(int i = 0; i<n; i++){
		for(int j=0; j<m; j++){
			
			cin >> gold[i][j];
		}
	}
	

	goldDigger(gold);
	
}

