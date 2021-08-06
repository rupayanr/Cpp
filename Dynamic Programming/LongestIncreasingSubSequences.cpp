#include <bits/stdc++.h>
using namespace std;

void findLongestIncSubSeq(vector<int> &nums){
	/*
		Problem: Find the longest subsequence of given array that is arranged in an increasing order 
		
		10 5 9 16 20 -> 5 9 16 20 
		
		Algo:
		
		[ 10 21 33 56 45 70 19 15 3 ]
		
		1) Make a dp array and fill it according to these rules 
		2) dp[i] gives the longest inc ss of the arr[i] value as the last value 
		 10 -> _ | 10
		 21 -> if(21 > 10) -> 10 20 -> 2
	     33 -> 31 > 10 and 31 > 21 so max(prev value's max) + 1 = 2 + 1 = 3
		[ 1, 2, 3, 4, 4, 5, 2, 2, 1 ] 
	*/
	int n = nums.size();
	int olen = 0;
	
	int dp[n];
	
	for(int i=0; i<n; i++){
		int len = 0;
		for(int j=0; j<i; j++){
			if(nums[j] < nums[i]){
				len = max(len, dp[j]);
			}
		}
		
		dp[i] = len + 1;
		olen = max(olen, dp[i]);
	}
	
	cout << olen << endl;
}	

int main(){
	int n; 
	cin >> n;
	
	vector<int> nums(n);
	
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
	
	findLongestIncSubSeq(nums);
}
