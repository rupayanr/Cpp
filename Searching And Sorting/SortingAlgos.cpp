#include<bits/stdc++.h>
#define vi vector<int> 
#define mii map<int,int>
using namespace std;



bool comp(vi &nums, int i, int j){
	
	if(nums[j] < nums[i]){
		return true;
	}
	return false;
}

void swap(vi &nums, int i, int j){
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

int partition(vi &nums, int pivot, int lo, int hi){
    
    int i = lo, j = lo;
    while (i <= hi) {
      if (nums[i] <= pivot) {
        swap(nums, i, j);
        i++;
        j++;
      } else {
        i++;
      }
    }
    return (j - 1);
}

void quickSelect(vi &nums, int lo, int hi, int k){
	
	// Fetch partition index 
	int pi = partition(nums, nums[hi], lo, hi);
	
	// If the partition index is > than k that means kth element lies the left half of pi
	if(k < pi){
		
		quickSelect(nums, lo, pi - 1, k);
	}
	else if(k > pi){
		
		quickSelect(nums, pi + 1, hi, k);
		
	}
	else{
		cout << nums[pi] << endl;
	}
	
}

void quickSort(vi &nums, int lo, int hi){
	if(lo > hi){
		return;
	}
	
	int pivot = nums[hi];
	int pi = partition(nums, pivot, lo, hi);
	quickSort(nums, lo, pi-1);
	quickSort(nums, pi+1, hi);
	
}

void merge(vi &nums, int lo, int mid, int hi){
	// [ 8 7 1 2 4 3]
	
	// Size of left sub array 
	int l = mid - lo + 1; 
	// Create a vector of len l that stores the left part of nums
	vi al(l);
	// Size of right sub array 
	int r = hi - mid; 
	vi ar(r);
	
	// Starting from lo add till l 
	for(int i=0; i<l; i++){
		al[i] = nums[i+lo];
	}
	// Starting from mid add till hi 
	for(int i=0; i<r; i++){
		ar[i] = nums[mid + 1 + i];
	}
	
	// Main merger sort algo 
	int i = 0, j = 0, k = lo;
	
	while(i < l && j < r){
		
		if(al[i] <= ar[j]){
			nums[k++] = al[i++];
		}
		else{
			nums[k++] = ar[j++];
	
		}
		
	}
	
	while(i < l){
			nums[k++] = al[i++];
	}
		
	while(j < r){
			nums[k++] = ar[j++];
	}
	
	
	
}

void mergeSort(vi &nums, int lo, int hi){
	
	
	if(hi > lo){
		int mid = (hi + lo)/2;
		
		mergeSort(nums, lo, mid);
		
		mergeSort(nums, mid+1, hi);
		
		merge(nums, lo, mid, hi);
	}
	
	
}

void insertionSort(vi &nums){
	
	/*
		Reverse bubbling technique 
		
		Since one element in a vector is already sorted we can start comparing from 2st element 
		if inner element are greater than th outer we keep swapping it till it reaches its destination 
		
	*/
	
	for(int i=1; i<nums.size(); i++){
		for(int j = i-1; j>=0; j--){
			
			if(comp(nums,j, j+1)){
				swap(nums,j,j+1);
			}else{
				// Only if the jth el is greater will it swap 
				// Time complexity could be good in avg case 
				break;
			}
		}
	}
}

void selectSort(vi &nums){
	
	/*
		Similar to Bubble sort but instead of pushing max to end 
		we pull min to front 
		
		Outer loop again N-1 iterations for N element 
		We start by keeping a minIdx as i and starting j at minIdx + 1
		
		if(arr[j] is < arr[min]) {min = j}
		
		at the end of each iteration we swap arr[i] with arr[min] 
		then we move on to the next iteration 
		 
	*/
	
	for(int i = 0; i < nums.size() - 1; i++){
		int minIdx = i;
		for(int j = i+1; j < nums.size(); j++){
			
			if(comp(nums, minIdx, j)){
				minIdx = j;
			}
				
		}
		swap(nums, i, minIdx);
	}
	
	
}

void bubbleSort(vi &nums){
	// You have to bubble the largest element to the end in each iteration 
	
	// For N elements number of iterations required is N-1 
	
	/* 
		Inner loop (j, j+1) runs only till N - Iterations so (1, N-1) (2, N-2)... 
		because after every iteration we know that the max element is in 
		its correct place after each iteration
	*/ 
	
	int n = nums.size();
	for(int itr = 1; itr <= n - 1; itr++){
		for(int j=0; j < n - itr; j++){
			
			if(comp(nums,j,j+1)){
				swap(nums,j,j+1);	
			}
		}
	}
	
}

void countSort(vi &nums){
	
	/*
		Used when you have repeated numbers in a fixed range 	
	*/
	// [ 9 8 2 3 4 3 6 9 2 8 9 ]
	// First we have to create a frequency map 
	//mii map;
	
	/*
	for(auto el: nums){
		if(map.find(el) != map.end()){
			map[el] += 1;
		}
		else{
			map[el] = 1;	
		}
	} */
	
	// Unstable Sort
	/*
	vi res;
	
	for(auto pr : map){
		for(int i = pr.second; i>0; i--){
			res.push_back(pr.first);
		}
	}
	
	for(auto el: res){
		cout << el << " ";
	}
	cout << endl;
	*/
	
	// Stable Sort 
	
	int maxV = *max_element(nums.begin(), nums.end());
	int minV = *min_element(nums.begin(), nums.end());
	int n = nums.size();
	int len = maxV - minV + 1;
	
	vi freq(len, 0);
	// [ 9 8 2 3 4 3 6 9 2 8 ]
	for(int i = 0; i<n; i++){
		freq[nums[i] - minV] += 1;
	}
	// Convert frequency array to prefix sum array 
	for(int i=1; i<len; i++){
		freq[i] += freq[i-1];
	}
	
	vi ans(n);
	
	for(int i = n-1; i>=0; i--){
		
		int idx = nums[i] - minV;
		int pos = freq[idx]  - 1;
		ans[pos] = nums[i];
		freq[idx] -= 1;
	}
	
	for(auto el: ans){
		cout << el << " ";
	}
	cout << endl;
}

void sort01(vi &nums){
	
	int i=0, j=0;
	while(i < nums.size()){
		if(nums[i] == 0){
			swap(nums, i, j);		
			i++;
			j++;
		}
		else{
			i++;
		}
	}
	
}

void sort012(vi &nums){
	int i=0, j=0, k=nums.size() - 1;
	
	while(i <= k){
		if(nums[i] == 0){
			swap(nums,i,j);
			i++;
			j++;
		}
		else if(nums[i] == 1){
			i++;
		}
		else{
			swap(nums,i,k);
			k--;
		}
	}
	
}


void targetSumPair(vi &nums, int target){
	//sort(nums.begin(), nums.end());
	
	mergeSort(nums,0, nums.size() - 1);
	int i = 0, j = nums.size() - 1;
	
	while(i <= j){
		int sum = nums[i] + nums[j];
		if(sum < target){
			i++;
		}else if (sum > target){
			j--;
		}
		else{
			cout << nums[i] << " " << nums[j] << endl;
			i++;
			j--;
		}
	}

}

int main(){
	int n;
	cin >> n;
	
	vi nums(n);
	
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
	targetSumPair(nums, 15);
	
	//quickSort(nums, 0, n - 1);
	
	for(int num: nums){
		cout << num << " ";
	}
	cout << endl;
	

}
