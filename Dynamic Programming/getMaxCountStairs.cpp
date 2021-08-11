#include<bits/stdc++.h>
using namespace std;

void getMaxCounts(int n){
	
	int dp[n+1];
	dp[0] = 1;
	
	for(int i=1; i<=n; i++){
		if(i == 1){
			dp[i] = dp[i-1];
		}
		else if(i == 2){
			dp[i] = dp[i-1] + dp[i-2];
		}
		else{
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		}
	}
	
	
	cout << dp[n] <<endl;
	
} 


int main(){
	int n;
	cin >> n;
	getMaxCounts(n);
	
}
