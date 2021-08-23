#include<bits/stdc++.h>
#define vi vector<int> 

using namespace std;

void getArrangements(int n, int m){
	// n len 
	// m width 
	
	vi dp(n+1);
	for(int i=1; i<=n; i++){
		if(i < m){
			dp[i] = 1;
			
		}
		else if(i == m){
			dp[i] = 2;
		}
		else{
			dp[i] = dp[i-1] + dp[i-m];
		}
	}
	
	cout << dp[n];
}

int main(){
	int n,m;
	cin >> n>> m;
	
	getArrangements(n,m);
}

