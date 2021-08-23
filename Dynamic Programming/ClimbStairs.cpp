#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

/*
	Problem: You are give N floors, you have to find the number of patsh you can take to reach 0th floor 
	given you can jump 1, 2 or 3 floors at one time.
	
	Intuition: 
	
	From S -> D You have three choices 
		either take 1 jump 
		or 2 
		or 3 
		Total will be the summations of all the steps taken = Total paths 

	
*/ 

int getPaths(int floor){ // Say floor = 6
	
	// Tabulation Solution 
	//  0 1 2 3 4 5 6
	// [1 1 2 4 ]
	// So for each index we calculate weather if the jump from that index what is the total steps to be taken 
	
	vi dp(floor+1, 0); // Make a dp of floor + 1 size ans will be in dp[floor]
	// Trivial Case when floor is 0 then dp[0]=1 there is one way that is standing still 
	dp[0] = 1;
	for(int i=1; i<=floor; i++){
		
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
	
	return dp[floor];
	
	
}

int main(){
	
	int res = getPaths(10);
	cout << res << endl;
}
