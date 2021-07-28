#include<bits/stdc++.h>
using namespace std;

int findTarget(vector<int> &nums, int target){
	unordered_map <int,int> umap;
	
	for(int i = 0; i<nums.size(); i++){
		umap[nums[i]] = i;	
	}
	
	sort(nums.begin(), nums.end());
	int res = 0;
	int left = 0;
	int right = nums.size() - 1;
	
	while(left <= right){
		
		int mid = left + (right - left)/2;
		
		if(nums[mid] == target){
		
			return umap[nums[mid]];
			
		}
		
		if(nums[mid] > target){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}

	}
	
	return -1;
}

int main(){
	int n;
	cin>>n;
	
	vector<int> nums(n);
	
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
	int t; 
	cin >> t;
	int res = findTarget(nums,t);
	cout << res;
}
