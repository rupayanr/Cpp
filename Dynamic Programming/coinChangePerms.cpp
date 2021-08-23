#include<bits/stdc++.h>
#define vi vector<int> 
using namespace std;

void getPermCount(vi &coins, int pay){
	
	vi dp(pay+1, 0);
	
	dp[0] = 1;
	for(int i=0; i<=pay; i++){
		for(int coin : coins){
			if(i - coin >= 0){
				dp[i] += dp[i-coin];
			}
		}
	}
	
	cout << dp[pay]<<endl;
}

int main(){
	int n;
	cin >> n;
	
	vi coins(n);
	
	for(int i=0; i<n; i++){
		cin >> coins[i];
	}
	
	int pay; 
	cin >> pay;
	
	getPermCount(coins, pay);
}
