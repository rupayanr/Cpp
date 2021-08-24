#include<bits/stdc++.h>
#define vi vector<int> 
#define vvi vector<vector<int>> 

using namespace std;

int getPairs(int n){
	vi dp(n+1);
	
	dp[1] = 1;
	dp[2] = 2;
	
	for(int i=3; i<=n; i++){
		dp[i] = dp[i-1] + (i-1) * dp[i-2];
	}
	
	return dp[n];
}

int main(){
	
	int n;
	cin >> n;
	
	int ans = getPairs(n);
	cout << ans << endl;
	
	return 0;
}


