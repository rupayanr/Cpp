#include <bits/stdc++.h>
using namespace std;

bool _canSum(int target, vector<int> nums, unordered_map<int,bool> &map){
	
	// Base case 1 
	if(target == 0){
		return true;
	}
	
	// Base case 2
	if(target < 0){
		return false;
	}
	
	// If target sum already exists in map return the value
	if(map.find(target) != map.end()){
		return map[target];
	}
	
	// For every element check if remainder has a return val of true in _canSum
	for(int i=0; i<nums.size(); i++){
		
		int rem = target - nums[i];
		if(_canSum(rem,nums,map)){
			map[target] = true;
			return true;
		}
	}
	
	map[target] = false;
	return false;
	
	
}

bool canSum(int target, vector<int> nums){
	
	unordered_map<int,bool> map;
	return _canSum(target,nums,map);
	
}

int main(){
	
	vector<int> nums = {2,3,5};
	if(canSum(80,nums)){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
}
