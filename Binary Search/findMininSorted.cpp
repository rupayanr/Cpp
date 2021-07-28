#include <bits/stdc++.h>
using namespace std;

int findMinBS(vector<int> &nums){
	
	int left = 0, right = nums.size() - 1;
	while(nums[left] > nums[right]){
		
		int mid = left + (right - left)/2;
		
		if(nums[mid] > nums[left]){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	
	return nums[left];
}

int findMin(vector<int> &nums){
	
	for(int i = 1; i<nums.size(); i++){
		
		// Finds the deflection point 
		if(nums[i-1] > nums[i]){
			return nums[i];
		}
	}
	
	// If the nums vector is rotated such that it comes to its original sorted position 
	return nums[0];
	
}

int main(){
	vector<int> nums ={11,13,15,17};
	int ans = findMinBS(nums);
	cout << ans;
}
