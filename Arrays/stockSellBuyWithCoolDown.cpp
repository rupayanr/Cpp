#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

/*
	Problem: 
	This time there is a cooldown period of one day
	So you'll have to maintain best cooldown state 
	
*/

void getMaxProfitWithCoolDown(vi &prices){
	// 10 15 17 20 16 18 22 20 22 20 23 25 //

	int obs = -prices[0]; // -10 
	int oss = 0; 
	int ocs = 0; 
	
	for(int i=1; i<prices.size(); i++){
		
		int nbs = 0;
		int nss = 0;
		int ncs = 0;
		
		
		nbs = max(ocs - prices[i], obs); // -10 -10 
		nss = max(prices[i] + obs, oss); // 5
		ncs = max(oss,ocs); // 0 
		
		obs = nbs; // -10 
		oss = nss; // 5 
		ocs = ncs;	// 0
	}
	
	cout << oss << endl;
}


int main(){
	
	int n;
	cin >> n;
	vi prices(n);
	
	for(int i=0; i<n; i++){
		cin >> prices[i];
	}
	
	getMaxProfitWithCoolDown(prices);
	 
}
