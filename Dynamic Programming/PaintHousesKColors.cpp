#include<bits/stdc++.h>
#define vi vector<int> 
#define vvi vector<vector<int>>
using namespace std;

void getMinCost(vvi &cost){
	int h = cost.size();
	int c = cost[0].size();
	
	vvi dp(h,vi(c));
	
	for(int j=0; j<c; j++){
		dp[0][j] = cost[0][j];
	}
	
	for(int i=1; i<h; i++){
		for(int j=0; j<c; j++){
			
			int minC = INT_MAX;
			for(int k=0; k<c; k++){
				
				if(k != j){
					minC = min(minC, dp[i-1][k]);
				}
			}
			
			dp[i][j] = cost[i][j] + minC;
		}
	}
	
	int minR = INT_MAX;
	for(int j=0; j<c; j++){
		
		minR = min(minR, dp[h-1][j]);
	}
	
	cout << minR;
	
}


int main(){
	int n, k;
	cin >> n >> k;
	
	vvi cost(n,vi(k));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			cin >> cost[i][j];  
		}
	}
	
	getMinCost(cost);
	 
	
}
