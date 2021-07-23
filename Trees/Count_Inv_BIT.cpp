#include <bits/stdc++.h>
using namespace std;

/* 
* Problem: Count Inversions in an array 
* Inversion : a[i] > a[j] for i < j 
* Input Array : { 8 4 9 2 } we have 6 inversion 
  
* Intuition : We calculate the maximum element of the given array and construct a bit starting from (1, 2, 3 ...maxelement) size max+1
	now what we can do is if sum(max) - sum(element) is greater that zero which means the element occured before the max element or elements < max
	but > input element 
	else we can update the bit[element] += 1
* * To Accomodate -ve numbers we can use relative numbering 
	  
  Algo using Binary Indexed Tree (BIT)
  1) Find max element of given input array
  2) Construct a bit array of zeroes from 1 to max (size = max+1)
  3) loop through the given array and find sum(max) - sum(a[i]) 
  4) Add that to invcount 
  5) update the value of bit[a[i]] = 1
  
  */
  
void update(vector<int> &bit, int n, int index, int val){
	while(index <= n){
	
		bit[index] += val;
	
		index += index & (-index);
		
	}
	
} 
  
int sum(vector<int> &bit, int index){
	int sum = 0;
	while(index > 0){
		sum += bit[index];
		
		index -= index & (-index);
	}
	
	return sum;
} 
  
int countInv(vector<int> vec){
	
	int inv = 0;
	// Extracting the max element of the given vector
	int max = *max_element(vec.begin(),vec.end());
	
	vector<int> bit(max+1);
	
	for(auto i:vec){
	
		int diff = sum(bit,max) - sum(bit,i);
	
		if(diff){
			
			inv += diff;
		}
		
		update(bit,max,i,1);
	}
	
	
	return inv;
	
	
}  
  
int main(){
	
	
	vector<int> vec;
	int n;
	cout << "Enter size of Array: ";
	cin >> n;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		vec.push_back(x);
	}
	int res = countInv(vec);
	cout << res;
		
}
