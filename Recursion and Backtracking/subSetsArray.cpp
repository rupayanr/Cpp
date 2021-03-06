#include<bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int> 
#define pb push_back
using namespace std;
// Try bit manipulation method 

vvi result;

vvi getSubsets(vi &nums){
	
	vvi subsets = {{}};
	
	for(int num: nums){
		int n = subsets.size();
		cout << "Size: "<<n<<endl;
		
		for(int i=0; i<n; i++){
			subsets.pb(subsets[i]);
			subsets.back().pb(num);
		}
	}
	
	for(auto vec: subsets){
		for(auto el: vec){
			cout << el <<"";
		}
		cout << endl;
	}
	
	return subsets;
}

void getSubArrays(vi nums, int i, vi &subset){
	
	// { 10 30 40 22 } -> {} {10} {10 30} {10 30 40} {10 20 30 40 22} 
	// {30} {30 40} {30 40 22} 
	
	// Base Case 
	if(i == nums.size()){
		
		cout << "Subset{}: ";
		for(auto el:subset){
			cout << el << " ";
			
		}
		cout << endl;
		result.pb(subset);
		return;
	}
	
	// Case / Decision when we don't include nums[i] in the subset
	getSubArrays(nums, i+1,subset);	
	
	// Case / Decision when we add it to the subset
	subset.pb(nums[i]);
	getSubArrays(nums,i+1,subset);
	
	// Backtracking so that we can get both the results 
	subset.pop_back();
	
	
}

int main(){
	int n;
	cin >> n;
	vi nums(n);
	
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
	
	vi subset;
	getSubArrays(nums,0,subset);
	
	for(auto vec: result){
		for(auto el: vec){
			cout << el << " ";
		}
		cout << endl;
	}
	
	vvi ans = getSubsets(nums);

}
