#include<bits/stdc++.h>

using namespace std;

void countSS(string s){
	int n = s.size();

	int dp[n][n];
	
	for(int g = 0; g < n; g++){
		
		for(int i=0, j=g; j < n; i++, j++){
			
			if(g == 0){
				dp[i][j] = 1;
			}
			else if(g == 1){
				dp[i][j] = (s[i] == s[j]) ? 3 : 2;
			}
			else{
				if(s[i] == s[j]){
					dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
				}
				else{
					dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
				}
			}
		}
	}
	
	cout << dp[0][n-1];
	
	
}

int main(){
	string s;
	getline(cin,s);
	countSS(s);
}
