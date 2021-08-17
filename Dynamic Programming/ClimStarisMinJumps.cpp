#include<bits/stdc++.h>
#define vi vector<int> 

using namespace std; 

/*
	Problem: 
	Array of Max jumps
	Find possible number of paths where you can take jumps as much as the max jumps 
	You can choose to take fewer jumps 

*/ 

void getPaths(vi &jumps){
	// 10
	//  0 1 2 3 4 5 6 7 8 9 
	//[ 3 3 0 2 1 2 4 2 0 0 ]

	int n = jumps.size(); // 10 
	vi dp(n+1,0); // 0 1 2 3 4 5 6 7 8 9 10
	dp[n] = 0; // [  5 3 0 2 1 1 1 0 0 0 1 ]
	
	for(int i=n-1; i>=0; i--){ // 9 8 7 6 5 4
		int m = jumps[i]; // 0 0 2 4 2 1 
		
		if(m == 0){
			dp[i] = INT_MAX;
		}
		else{
			int minVal = INT_MAX;
			for(int j=1; j<=m && i+j <=n; j++){ //    
				
					minVal = min(minVal,dp[i+j]); // 
			}
			
			if(minVal != INT_MAX){
				dp[i] = minVal + 1;	
			}else{
				dp[i] = minVal;
			}
			
		}
 	}
	
	cout << dp[0] << endl;
	
	
}

int main(){
	int n;
	cin >> n;
	vi jumps(n);
	
	for(int i=0; i<n; i++){
		cin >> jumps[i];
	}
	
	getPaths(jumps);
}

