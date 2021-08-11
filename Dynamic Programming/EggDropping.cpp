#include<bits/stdc++.h>
using namespace std;

/*
	Problem: 
	Given no. of floors and no. of eggs in basket find min attempts by which you can find 
	the critical floor 
	
*/


void getMinAttempts(int e, int f){
	
	int dp[e+1][f+1];
	
	for(int i=0; i<1; i++){
		for(int j=0; j<1; j++){
			dp[i][j] = 0;
		}
	}
	
	for(int i=1; i<=e; i++){
		for(int j=1; j<=f; j++){
			
			if(j == 1){
				dp[i][j] = 1;
			}
			else if(i == 1){
				dp[i][j] = j;
			}
			else{
				int best = INT_MAX;
				for(int mf = j - 1, pf = 0; mf >= 0; mf--, pf++){
					
					int worst = max(dp[i][mf], dp[i-1][pf]);
					best = min(best,worst); 
					
				}
				dp[i][j] = best + 1;
				
			}
			
		}
	}
	

	cout << dp[e][f] << endl;
		
}

int main(){
	int e, f;
	cin >> e >> f;
	getMinAttempts(e,f);
	
}
