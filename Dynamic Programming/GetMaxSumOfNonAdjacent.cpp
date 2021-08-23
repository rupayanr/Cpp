#include<bits/stdc++.h>
#define vi vector<int> 
using namespace std;
 
/*
	Problem: 
	To get max sum of non adjacent elements in an array 
	
	Solution: Include : Exclude principal 
	
    	5 10 10 25 10 5 7 
inc   [ 5 10 15 35 25 40 42	]
exc   [ 0 5	 10 15 35 35 40 ]

Funda: When you exclude a number you have to choose the maximum of previous includes ( Greedy ) 
		When you inc that number take the sum with prev excluded sum

Ans = 42 
	
*/ 
 
void getMaxSum(vi &nums){
	
	int inc = nums[0]; 
	int exc = 0;
	
	for(int i=1; i<nums.size(); i++){
		int ninc = exc + nums[i];
		int nexc = max(inc,exc);
		
		exc = nexc;
		inc = ninc; 
	}
		
	int res = max(exc,inc);
	cout << res << endl;
	
	
} 
 
int main(){
	int n; 
	cin >> n; 
	vi nums(n,0);
	
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
	
	getMaxSum(nums);
}
