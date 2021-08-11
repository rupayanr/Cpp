#include<bits/stdc++.h>

using namespace std; 




void countPaliSubstr(string s){
	
	int longest = 0;
	
	bool dp[s.size()][s.size()];
	
	for(int g = 0; g<s.size(); g++){
		
		for(int i=0, j=g; j<s.size(); i++, j++){
			
			if(g == 0){
				dp[i][j] = true;
			}
			else if(g == 1){
				if(s.at(i) == s.at(j)){
					dp[i][j] = true;
				}
				else{
					dp[i][j] = false;
				}
			}
			else{
				if(s.at(i) == s.at(j) && dp[i+1][j-1]){
					dp[i][j] = true;
					
				}
				else{
					dp[i][j] = false;
				}
			}
			
			if(dp[i][j]){
				longest = max(longest,g+1);
			} 

		
		}
			
	}
	
	for(int i=0, j=longest-1; j<s.size(); i++, j++){
		if(dp[i][j]){
			return s.substr(i,longest);
		}
	}
	
	
} 

int main(){
	
	string s;
	getline(cin,s);
	
	countPaliSubstr(s);
	
}
