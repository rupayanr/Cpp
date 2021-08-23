#include<bits/stdc++.h>
#define vi vector<int>

using namespace std; 
/*
	Problem: 
	Given encodings of each number with alphabet 
	1 - a 
	2 - b
	3 - c 
	.
	.
	.
	.
	23 - w
	24 - x
	25 - y
	26 - z
	
	You are given a string you have to count the no. of encodings possible in that string 
	
	123 - ans 3 
	abc - 1 2 3 
	lc  - 12 3
	aw  - 1 23 
	
	SOLUTION: 
		* Means the count encodings till that substr
	  1 2 2 3 1 0 		
	[ 1 2 3 5 5 5] 	
	
	  a ab aba
		l	la
			au
		i-2		i-1   i
	[--------]------]---
	dp[i] = dp[i-1] + dp[i-2]
	
    Sepcial Cases: 
    
    i >= 2 dp[i-2] : 1
	
	if( s[i-1] == 0 & s[i] == 0) 
	dp[i] = 0 
	


*/

void getEncodings(string s){ // 2 0 1 0 
	int n = s.size();
	
	vi dp(n, 0);
	
	dp[0] = 1;
	
	for(int i=1; i<n; i++){
		
		if( s[i] == '0' && s[i-1] == '0' ){
			dp[i] = 0;
		}
		else if( s[i] == '0' && s[i-1] !='0' ){
			char prev = s[i-1];
			
			if(prev == '1' || prev == '2'){
				dp[i] = i>=2 ? dp[i-2] : 1;	
			}
			else{
				dp[i] = 0;
			}
			
		}
		else if( s[i] != '0' && s[i-1] == '0' ){
			
			dp[i] = dp[i-1];
			
		}
		else{
			int last = stoi(s.substr(i-1,i+1));
	
			
			if(last <= 26){
			
				dp[i] = dp[i-1] + (i>=2 ? dp[i-2] : 1);
			}
			else{
			
				dp[i] = dp[i-1];
			}
		}
		
		
	}
	
	
	cout << dp[n-1] << endl;
	
}


int main(){
	string s;
	getline(cin,s);
	
	getEncodings(s);
}

