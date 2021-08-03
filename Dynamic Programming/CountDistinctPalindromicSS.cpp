#include<bits/stdc++.h>
using namespace std;

int countDistinctPalindromes(string s){
	
	int n = s.size();
	int dp[n][n];
	
	int next[n]; int prev[n];
	
	unordered_map <char,int> map;
	
	for(int i=n-1; i>=0; i--){
		char ch = s[i];
		
		if(map.find(ch) != map.end()){
			next[i] = map[ch];
		}
		else{
			next[i] = -1;
		}
		
		map[ch] = i;
	}
	map.clear();
	
	for(int i=0; i<n; i++){
		char ch = s[i];
		
		if(map.find(ch) != map.end()){
			prev[i] = map[ch];
		}
		else{
			prev[i] = -1;
		}
		
		map[ch] = i;
	}
	
	for(int g = 0; g < n; g++){
		
		for(int i = 0, j=g; j < n; i++, j++){
			
			if(g==0){
				dp[i][j] = 1;
			}
			else if (g==1){
				dp[i][j] = 2;
			}
			else{
				
				if(s[i] != s[j]){
					dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]; 
				}
				else{
					int nis = next[i];
					int pis = prev[j];
					
					if(nis > pis){
						dp[i][j] = 2 * dp[i+1][j-1] + 2;
					}
					else if(nis == pis){
						dp[i][j] = 2 * dp[i+1][j-1] + 1;
					}
					else{
						dp[i][j] = 2 * dp[i+1][j-1] - dp[nis+1][pis-1];
					}
				}
				

			}
		} 
	}
	
	return dp[0][n-1];
	
}

int main(){
	
	string s; 
	getline(cin,s);
	int res = countDistinctPalindromes(s);
	cout << res << endl;
	
}
