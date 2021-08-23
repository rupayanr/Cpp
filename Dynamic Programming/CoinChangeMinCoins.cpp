#include<bits/stdc++.h>
#define vi vector<int> 

using namespace std; 
	/*
		Intuition : 
		We can try each combination of coins one after the another and take the minimum
		amount of coins each time 
		
		So lets say we have to pay 6rs using 2,3 and 5 coins 
		Ans should be 2 coins of 3 
		
		dp[0] = 0; We require 0 coins to pay 0rs be it of any denominations 
		[2, 3, 5] 
		
		 0 1 2 3 4 5 6
		[0 INT_MAX INT_MAX INT_MAX....]
		
		First we see with 2 what all can we pay 
		[ 0 INT_MAX 1 ...	  We see that dp[i - coin] i.e 2 - 2 dp[0] is not INT_MAX so we can pay it using 1 coin 
		
		For 3 dp[i - coin] = dp[1] which is INT_MAX hence we cannot pay it using 2 coin. 
		
		
		dp[i] = min(dp[i], dp[i-1] + 1) 
		
		It is better to sort the coin arrangement before hand so that we can do this gradually but It might not be necessary 
	*/
int getMinCoins(vi &coins, int amount){
	
	// Construct a dp storage of amnt + 1
	vi dp(amount+1, INT_MAX);
	dp[0] = 0;

	for(int coin: coins){
		for(int i=1; i<=amount; i++){
			
			if(coin <= i){
					
				if(dp[i-coin] != INT_MAX){
					dp[i] = min(dp[i], dp[i-coin] + 1);	
				}
			}		
		}
			
	}
	
	return dp[amount] == INT_MAX ? -1 : dp[amount];
	
	
}

int main(){
	int n;
	cin >> n;
	vi coins(n);
	
	for(int i=0; i<n; i++){
		cin >> coins[i];
	}
	int amount; 
	cin >> amount;
	
	int res = getMinCoins(coins,amount);
	cout << res << endl;
}

