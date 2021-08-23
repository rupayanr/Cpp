#include<bits/stdc++.h>

using namespace std;

/*
	Problem: 
	Given no. of floors and no. of eggs in basket find min attempts by which you can find 
	the critical floor fc.  
	
						Breaks 				p1
					   __________	(e - 1 / k - 1) (Means the fc will below k)  	
					  |	
			k floors  |			ANS = MIN (Max(p1, p2) + Max(p3, p4) + .... )															
	e | f ------------|																
					  |			      p2
					  |__________ ( e / f - k ) ( Means we have to check from above floor) 

						Survives 


*/	


void getMinAttempts(int e, int f){
	
	int dp[e+1][f+1]; // Constructing an e+1 * f+1 matrix to tabulate 
	
	// Fill it with zeroes 
	for(int i=0; i<1; i++){
		for(int j=0; j<1; j++){
			dp[i][j] = 0;
		}
	}
	
	// For i = 0 it will remain 0 as 0 eggs mean zero attempts
	 
	
	for(int i=1; i<=e; i++){
		for(int j=1; j<=f; j++){
			
			if(j == 1){
				// If floor is only 1 then min attempt is also 1
				dp[i][j] = 1;
			}
			else if(i == 1){
				// For i = 1 so which ever floor is given worst we have to traverse all floors dp[i][j] = j
				dp[i][j] = j;
			}
			else{
				// Init var with max value as we have to take min value in the end 
				int best = INT_MAX;
				for(int mf = j - 1, pf = 0; mf >= 0; mf--, pf++){
					/* Understanding the pattern by solving few cells 
						we observe that we have to compare my floor with previous floor 
						mf starts from j - 1 and pf starts from 0 
						[0-> 1 2 3]
						[0 1 2 <-2] *Cell to be found  
					*/ 
					
					// Assuming worst luck we take out maximum of each comparison 
					int worst = max(dp[i][mf], dp[i-1][pf]);
					
					// Then we take minimum of those worst case maximums 
					best = min(best,worst); 
					
				}
				
				// Then we add it to the dp with +1 since it takes additional step to drop the egg 
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
