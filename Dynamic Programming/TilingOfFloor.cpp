#include<bits/stdc++.h>
#define vi vector<int> 

using namespace std;
/*
	Problem: We have a 2*N floor and we have to lay down 2*1 tiles on it

*/

void getArrangements(int n){
	vi dp(n+1);
	dp[1] = 1;
	dp[2] = 2;
	
	for(int i=3; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	cout << dp[n] << endl;

}

int main(){
	
	int n; 
	cin >> n;
	getArrangements(n);	
	
}
