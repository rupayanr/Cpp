#include<bits/stdc++.h>
using namespace std;

void findFirstLastIndex(vector<int> nums, int target){
	
	int left = 0;
	int right = nums.size() - 1;
	
	while(left <= right){
		
		int mid = left + (right - left)/2;
		
		if(left == right && nums[left] != target){
			return -1;
		}
		
		
		if(target > nums[mid]){
			left = mid + 1;
		}
		else if(target < nums[mid]){
			right = mid - 1;
		}
		else{
			
			// Found the target value 
			
			while(nums[left] != target){
				left++;
			}
			
			cout <<left<<endl;
			
			while(nums[right] != target){
				right--;
			}
			
			cout<<right<<endl;
			
			break;
		}
	}
	
}

int main(){
	
	int n;
	cin >> n;
	
	vector<int> nums(n);
	
	for(int i=0; i<n; i++){
		
		cin >> nums[i];
	}
	int d;
	cin >> d;
	findFirstLastIndex(nums,d);
	
}
