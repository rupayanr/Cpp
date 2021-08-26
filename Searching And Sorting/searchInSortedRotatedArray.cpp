#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

void findPivot(vi &nums){
	// So if the array is sorted and rotated then there must be a trough 
	// [ 1 2 5 8 10 15 20 25] -> [ 10 15 20 25 1 2 5 8] Pivot is 1 
    //	                         lo         mid     hi
	int lo = 0; int hi = nums.size() - 1;
	
	while(lo < hi){
		int mid = lo + (hi - lo)/2;
		
		if(nums[mid] < nums[hi]){
			hi = mid;
		}
		else if(nums[mid] > nums[hi]){
			lo = mid + 1;
		}

	}
	cout << nums[lo];

}

int main(){
	int n;
	cin >> n;
	
	vi nums(n);
	for(int i = 0; i<n; i++){
		cin >> nums[i];
	}
	 
	findPivot(nums);
}
