#include <bits/stdc++.h>
using namespace std;
/* Problem Statement 

	Given a 1-D array of numbers find if a peak exists 
	
	[ 1 2 3 1 ] or [ 1 2 1 3 4 5 6 ]

*/

int findPeak(vector<int> &nums){
	
	int low = 0, high = nums.size() - 1;
	
	while(low < high){
		
		int mid = low + (high - low)/2;
		
		if(nums[mid] < nums[mid + 1]){
			low = mid + 1;
		}
		else{
			high = mid;
		}	
	}
	
	return low;
	
	
}

int main(){
	
	vector<int> nums = {1,2,3,1};
	int ans = findPeak(nums);
	cout << ans;
	
}
