#include<bits/stdc++.h>
#define vi vector<int> 
using namespace std;

/*
	Problem: 
	Prices of stock on ith day, cal max profit day for a single transaction 
	[ 11 6 7 19 6 2 18 10 ] 
	Max profit will be 18 - 2 = 16 
*/ 


int maxProfit(vi &prices){
	
	int minSell = INT_MAX;
	int profit = 0;
	int maxProfit = 0;
	
	for(int price : prices){ // 11 6 7 19 6 2 18 10 
		minSell = min(price,minSell); // 11 6 6 6 6 2 2 2
 		profit = price - minSell; // 0 0 1 13 0 0 16 8 
		maxProfit = max(profit, maxProfit); // 0 0 1 13 13 13 16 16 
	} 
	
	return maxProfit;
	
} 


int main(){
	
	int n;
	cin >> n;
	vi prices(n);
	
	for(int i=0; i<n; i++){
		cin >> prices[i];
	}
	
	int ans = maxProfit(prices);
	cout << ans << endl;
}

