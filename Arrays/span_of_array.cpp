#include <bits/stdc++.h>

using namespace std;

int max_el(vector<int> nums){
	
	int res=INT_MIN;
	
	for(int i=0; i<nums.size(); i++){
		if(nums[i] > res){
			res = nums[i];
		}	
	}
	
	return res;
}

int min_el(vector<int> nums){
	
	int res = INT_MAX;
	
	for(int i=0; i<nums.size(); i++){
		if(nums[i] < res){
			res = nums[i];
		}
	}
	
	return res;
}

int span(vector<int> &nums){
	
	int min = min_el(nums);
	int max = max_el(nums);
	int span = max - min;
	return span;	
}

int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
	
	int res = span(nums);
	cout << res;
}
