#include <bits/stdc++.h>

using namespace std;

    void reverse(vector<int> &nums, int lo, int hi){
    
        while(lo < hi){
            int temp = nums[hi];
            nums[hi] = nums[lo];
            nums[lo] = temp;
			lo++;
			hi--; 
        }
    }
    
    void rotateRev(vector<int>& nums, int k) {
    	// { 1 2 3 4 5 } k = 2 -> {  4 5 1 2 3 }
       int n = nums.size(); //5 
        
        while(k > n){
            k = k%n;
   		}
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
        
        for(auto el: nums){
        	cout << el << " ";
		}
		cout << endl;
    }


void rotate(int *arr, int n, int k){
	
	
	if(k < 0){
		k = k+n;
	}
	
	while(k >= n){
		k = k % n;
	}
	
	vector<int> rot(n);
	
	for(int i=0; i<n; i++){
		rot[(i+k) % n] = arr[i];
	}
	
	for(int i=0; i<n; i++){
		arr[i] = rot[i];
	}
}

void display(int *arr, int n){
	
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
		
	int n;
	cin >> n;
	
	vector<int> nums(n);
	
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
	int k;
	cin >>k;
	
	//rotate(arr,n,k);
	//display(nums,n);
	cout << endl;
	
	rotateRev(nums,k);
	
	
	
	
}
