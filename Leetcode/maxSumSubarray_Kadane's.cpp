#include <bits/stdc++.h>
using namespace std;

/* Algo (Kadane's Algo)
	
	Intuition: If the current sum is positive then add the array elements to it even if the element is negative, update the overall sum 
	to current is current > overall
	
	1) Start csum and osum with nums[0]
	2) Check if csum >= 0 then add a[i] else csum = a[i]
	3) Check if csum > osum then change osum = csum 
	4) Return osum

*/


int maxSumSubarray(vector<int> nums){
	int csum = nums[0];
	int osum = nums[0];
	
	for(int i=1; i<nums.size(); i++){
		
		if(csum >= 0){ 
			csum += nums[i];
		}
		else{
			csum = nums[i];
		}
		
		if(csum > osum){
			osum = csum;
		}
	}
	
	return osum;
}

int main(){
	
	vector<int> nums = {4 ,3, -1, 6, 7, 2, -10, -12, 7, 8, 2, 2};
	int res = maxSumSubarray(nums);
	
	cout << res;
	
	
}
