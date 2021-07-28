#include<bits/stdc++.h>
using namespace std;

void display(vector<int> nums){
	for(auto el: nums){
		cout << el << " ";
	}
	cout << endl;
}


void insert(vector<int> &nums, int target){
	
	// Base Case 
	// If array is empty or target is >= last element push back the target 

	display(nums);
	if(nums.size() == 0 || nums.back() <= target){
		nums.push_back(target);
		return;
	}
	
	int val = nums.back();
	nums.pop_back();
	
	insert(nums,target);
	nums.push_back(val);
	
}

void sortRec(vector<int> &nums){
	
	// { 5 4 3 2 7 8 9 } -> { 5 4 3 2 7 8 } = A  {9} = B -> insert(A,B)
	// {5 4 3 2 7 8} -> { 2 3 4 5 7 8 }
	// {5 4 3 2 7} {8} {9} ->..... {5} {4} {3} {2} {7}...
	
	// Base Case 
	if(nums.size() == 1){
		return;
	}
	
	// Caturing the last value
	int temp = nums.back();
	
	// Shrinking Array
	nums.pop_back();
	
	// Sorting the shrinked array recursively 
	sortRec(nums);
	
	// Inserting the last value into sorted array
	insert(nums,temp);
}

int main(){
	int n;
	cin >> n;
	
	vector<int> nums(n);
	
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
	
	display(nums);
	
	sortRec(nums);
	
	display(nums);
}
