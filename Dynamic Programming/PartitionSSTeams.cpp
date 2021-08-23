#include<bits/stdc++.h>
#define vi vector<int> 
#define vvi vector<vector<int>> 
using namespace std; 

/*
	Problem: Given no. of people N and no of teams to be divided into i.e K find out maximum such teams possible 
	
	i/p is 3 people and 2 teams 123[2]
			[13 - 2, 1-23, 12-3] 
			123[2] Can be divided into 2 scenarios
			 / \
			/   \
		12[2]	12[1] 
		[1 - 2] [12] 
		
		1)       2)
	
	1) Scenario is that 3 asks 12 to make 2 teams [1 - 2] and 3 says I can join any one of them so total -> 2*1 combination 
	2) Scenario is that 3 asks 12 to make 1 team and it becomes the other team [12] [12 - 3] so total 1 Combination
	
		f(n,k) = k * f(n-1,k-1) + f(n-1,k-1)

	Base Cases
	1) N = 0, 0 
	2) k = 0, 0 
	3) N = K, 1 -> say 10 people in 10 teams only 1 way 
	4) N < k, 0 
	5) N > K, f(n,k) 
	

*/


void getTeams(int n, int k){
	
	// Make a Dp of n+1 * k+1 
	vvi dp(n+1, vi (k+1, 0));
	
	// Fill the dp according to cases above 
	
	for(int i=0; i<=k; i++){
		for(int j=0; j<=n; j++){
			
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else if(i == j){
				dp[i][j] = 1;
				
			}
			else if(j < i){
				dp[i][j] = 0;
			}
			else{
				
				dp[i][j] = i * dp[i][j-1] + dp[i-1][j-1]; 
				
			}
		}
	}
	
	cout << dp[k][n] << endl;
	
}


int main(){
int n,k; 
cin >> n >> k;
getTeams(n,k);	
return 0;
}


