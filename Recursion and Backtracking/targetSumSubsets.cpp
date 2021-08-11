#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

void targetSumSubsets(vi nums, int i, string set, int sos, int tar){
	
	// Base Case
	if(i == nums.size()){
		if(tar == sos){
		set += ".";
		cout << set << endl;
		
		}	
	
	
		return;
	}
	
	// Result Case
	
	
	
	targetSumSubsets(nums, i+1, set, sos, tar);
	
	
	targetSumSubsets(nums, i+1, set + to_string(nums[i]) +", ", sos + nums[i], tar);
	
	
	
}

int main(){
	
    int n;
    cin >> n;
    vi nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    int tar; 
    cin >> tar;
	targetSumSubsets(nums,0,"",0,tar);
	
	
}
