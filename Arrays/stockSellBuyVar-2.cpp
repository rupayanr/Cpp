#include<bits/stdc++.h>
#define vi vector<int> 

using namespace std; 

/*
	Problem: 
	Maximum Profits you can gain having infinite transactions 
	Now you cannot make two buy orders that overlap 
	So configuration should be BS BS BS not BBSS 
*/

void getMaxProfits(vi &prices){
	// 11 9 18 6 2 20 3 15
	
	int profit = 0;
	int sell = 0; 
	int buy = 0;
	
	for(int i=1; i<prices.size(); i++){
		if(prices[i] >= prices[i-1]){
			sell++;
			
		}else{
			
			profit += prices[sell] - prices[buy];
			buy = sell = i;
			
		}
	}
	
	
	profit += prices[sell] - prices[buy];

	
	cout << profit;
	
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
