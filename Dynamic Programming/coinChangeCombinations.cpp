#include<bits/stdc++.h>
using namespace std;

/*
	Problem: Given an array of coins with certain value [2,3,5] with inifinte frequency of each coin.
			Find the maximum number of combinations possible for numbers in another array 

	
	DP -> 1) Storage and Meaning 
		   2) direction 
		   3) Travel and fill
	
	Intuition: 1) Make a DP array where each index is number that can be paid using the coins 
				2) Fill the array one by one such that dp[i] containes the no. of combinations of coins to pay dp[i]
*/

int giveCombinations(vector<int> &coins, int &pay){
	
	int dp[pay + 1] = {0};
	dp[0] = 1;
	
	for(int coin : coins){
	
		for(int j=coin; j<=pay; j++){ // 2
			dp[j] += dp[j - coin]; 		
		}
	}
	
	return dp[pay];
	
	
}


int main(){
	
	int n;
	cin >> n;
	
	vector<int> coins(n);
	
	for(int i=0; i<n; i++){
		cin >> coins[i];
	}
	int pay;
	cin >> pay;
	
	int res = giveCombinations(coins,pay);
	cout << res << endl;
	
}
