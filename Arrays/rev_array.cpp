#include <bits/stdc++.h>
using namespace std;

void display(vector<int> nums){
	for(auto el: nums){
		cout << el << " ";
	}
	cout << endl; 
	
}

void reverse(vector<int> &nums){
	
	/* ALGO 
		1) Start two pointers one from start and one from end 
		2) Swap start with end
		3) Increment start and decrement end Till start > = end
	*/
	
	int start=0;
	int end = nums.size() - 1;
	
	while(start < end){
		
		int temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++;
		end--;

	}
	
	
	
}

int main(){
	vector<int> nums = {8, 9 ,2 ,1};
	
	reverse(nums);
	display(nums);
}
