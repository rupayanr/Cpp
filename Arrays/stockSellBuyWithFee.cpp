#include<bits/stdc++.h>
#define vi vector<int> 
using namespace std;

/*
	Problem: 
	Find max profits with given fee 
	
	sol: Maintian old sold state profit and new sold state profit 
		Similarly maintaine old buy state and new buy state 
		
		if(osp - prices[i] > obp){
			nbs = osp - prices[i]
		}
		else{
			nbs = obp;
		}
		
		
		if(prices[i] - fee + obp > ssp)
		nssp = ^
		
		
		obsp = nbsp
		ossp = nssp

*/



void getMaxProfitWithFee(vi &prices, int fee){
	
	int n = prices.size();
	
	int oldBuyState = -prices[0];
	int oldSellState = 0;
	
	for(int i = 1; i<n; i++){
		
		int newBuyState = 0;
		int newSellState = 0;
		
		newBuyState = max(oldSellState - prices[i], oldBuyState);
		newSellState = max(prices[i] - fee + oldBuyState, oldSellState);
		
		
		
	/*	if(oldSellState - prices[i] > oldBuyState){
			newBuyState = oldSellState - prices[i];
		}
		else{
			newBuyState = oldBuyState;
		}
		
		if(prices[i] - fee + oldBuyState > oldSellState){
			newSellState = prices[i] - fee + oldBuyState;
		}
		else{
			newSellState = oldSellState;
		}
		*/
		oldBuyState = newBuyState;
		oldSellState = newSellState;
		
	}
	
	cout << oldSellState << endl;
	
}

int main(){
	
	int n;
	cin >> n;
	
	vi prices(n);
	
	for(int i=0; i<n; i++){
		cin >> prices[i];
	}
	
	int fee;
	cin >> fee;
	
	getMaxProfitWithFee(prices, fee);
	
}
