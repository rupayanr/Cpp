#include<bits/stdc++.h>
#define vi vector<int> 
using namespace std;

/*
	Problem: Stock sell buy but only two transactions are allowed
	Intuition is cal max profit keeping your transaction non overlapping BSBS
	
	1) You calculate the max profit for a given selling data 
	2) You calculate max profit after that for a particular buy date
	
	B------S B-----S 
	    max + max -> ans
	    
*/


void getMaxProfits(vi &prices){
	
	int n = prices.size();
	int maxProfitSellToday = 0;
	int leastBuy = prices[0];
	
	vi dp(n,0);

	
	for(int i=1; i<n; i++){
		
		leastBuy = min(leastBuy, prices[i]);
		
		int maxProfitSellToday = prices[i] - leastBuy;
		
		if(maxProfitSellToday > dp[i-1]){
			dp[i] = maxProfitSellToday;
		}
		else{
			dp[i] = dp[i-1];
		}
	}
	
	
	vi pd(n,0);
	int maxProfitBuyToday = 0;
	int maxSell = prices[n-1];
	
	for(int i = n-2; i >= 0; i--){
		
		maxSell = max(maxSell, prices[i]);
		
		maxProfitBuyToday = maxSell - prices[i];
		
		pd[i] = max(pd[i+1], maxProfitBuyToday);
	}
	
	int res = 0;
	for(int i=0; i<n; i++){
	
		res = max(res, dp[i]+pd[i]);	
	}
	
	cout << res << endl;
	
}

int main(){
	
	int n;
	cin >> n;
	vi prices(n);
	
	for(int i=0; i<n; i++){
		cin >> prices[i];
	}
	
	getMaxProfits(prices);
}
