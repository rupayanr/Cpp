#include <bits/stdc++.h>
using namespace std;


int findDup(vector<int> &nums){
	
	// This can be used in cse of mutable arrays and arrays of positive integer
	
	/* Algo:
	 -> For each element in nums vector update the element at nums[element] = -nums[element]
	 -> Always take abs(idx)
	 */
	 
	 for(int i=0; i<nums.size(); i++){
	 	
		if(nums[abs(nums[i])] >= 0){
			
			nums[abs(nums[i])] *= -1;
		}
		else{
			cout << abs(nums[i])<<" ";
		}
		
	 }
}


int findDuplicates(vector<int> &nums){
	
	// Algorithm : Floyd's Cycle 	
	// Initializing the slow and ast pointers to first element of nums array
	int slow=nums[0],fast = nums[0];
	//int fast = nums[0];
	
	do{
		// Shifting the pointers on the basis of index { Makeshift linked list idx->value->idx } 
		slow = nums[slow]; // Slow pointer jumps 1 node
		fast = nums[nums[fast]]; // Fast pointer jumps  nodes
	}
	while(slow != fast);
	
	// Resetting the fast pointer to 1st node
	fast = nums[0];
	
	while(slow != fast){
		// Moving the pointers at the same speed they are bound to meet at the intersection where x=y=i = starting node of the cycle
		slow = nums[slow];
		fast = nums[fast];
	}
	
	return fast;
}

int main(){
	vector<int> nums;
	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		nums.push_back(x);
	}
	
	
	int res = findDuplicates(nums);	
	cout << res <<endl;
	
	int ans = findDup(nums);
	cout << ans;
}
