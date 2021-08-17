#include<bits/stdc++.h>
#define vi vector<int> 
using namespace std;

void ubKnapSack(vi &keys, vi &cost, int cap){
	
	vi dp(cap+1, 0);
	
	for(int c=1; c<=cap; c++){
		int maxV = 0;
		for(int i=0; i<cost.size(); i++){
		
			if(keys[i] <= c){
				int rc = c - keys[i];
				int val = dp[rc] + cost[i];
				maxV = max(maxV, val); 
			
			}
		}
		dp[c] = maxV;
	}
	
	cout << dp[cap] << endl;
	
}

int main(){
	int n; 
	cin >> n;
	
	vi keys(n);
	vi costs(n);
	
	for(int i=0; i<n; i++){
		cin >> costs[i];
		
	}
	
	for(int i=0; i<n; i++){
		cin >> keys[i];	
	}		
	int cap; 
	cin >> cap; 
	
	ubKnapSack(keys,costs,cap);
	
}

