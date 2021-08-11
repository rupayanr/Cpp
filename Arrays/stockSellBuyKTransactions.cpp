#include<bits/stdc++.h>
#define vi vector<int> 
#define vvi vector<vector<int>>
using namespace std;
	
	// Make a DP with Days on the X Axis and No. of transactions on Y Axis
	
	/*
		Problem: 
		
		Given stock prices with max k transactions allowed
		find max profit 
			Days ---->
			9 10 6 3 4 15 7

			0  1 2 3 4  5 6
	k	0 [ 0  0 0 0 0  0 0 ]
 	|	1 [ 0  1 1 1 1	12 12 ]
	|	2 [ 0    *->*
	
		* Storing the best possible profit if I haev made 2 transactions on the 3rd day
			
		Intuition: 
		1) I have to fetch the max value of given candidates
			Candiates: 
				1) if d the day I have to check 
					int pr = dp[t][d-1]
				2)...
					int ppr = max(dp[t-1][d-1] - price[d-1])	+ price[d]
		dp[t][d] = max(pr,ppr)
	*/

void getMaxProfitsKTransactions(vi &prices, int k){
	
	int n = prices.size();
	
	vvi dp(k+1, vi(n,0));
	
	for(int t = 1; t<=k; t++){
		
		int maxV = INT_MIN;
		for(int d = 1; d<n; d++){
			
			maxV = max(dp[t-1][d-1] - prices[d-1], maxV);
			
			dp[t][d] = max(dp[t][d-1],maxV + prices[d]); 
		}
	}
	
	
	cout << dp[k][n-1]<<endl;
}


int main(){
	int n;
	cin >>n;
	
	vi prices(n);
	for(int i=0; i<n; i++){
		cin >> prices[i];
	}
	int k;
	cin >> k;
	
	getMaxProfitsKTransactions(prices,k);
}
