#include <bits/stdc++.h>
using namespace std;

int bSearch(vector<int> &nums, int target){
	
	// First we have to sort the nums vector 
	
	sort(nums.begin(), nums.end());
	/* Algo 
	
		1) Initilaize Left and Right with 0, n-1
		2) While (l<R) 
			2.a) Mid = l + (R-L)/2 (dont use L+R/2 it might cause overflow
			2.b) if nums[mid] == target return nums[mid]
			2.c) if nums[mid] < target L = mid + 1
			2.d) if nums[mid] > target R = mid - 1
			2.e) else return -1  
				
	*/
	
	int left = 0;
	int right = nums.size() - 1;
	
	while(left <= right){
		
		int mid = left + (right - left)/2; // 3 
		
		if(nums[mid] == target) return nums[mid]; 
		
		if(nums[mid] > target) {
			right = mid - 1; 
		}
		else{
			left = mid + 1;	
		}
		return -1;
	
	}
	
}


int main(){
	
	vector<int> nums = {4, 5 ,6,9,10,2,5};
	int ans = bSearch(nums,0);
	
	if(ans != -1){
		cout << ans;
	}
	else{
		cout << "Not Found";
	}
}
