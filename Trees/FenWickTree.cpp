#include <bits/stdc++.h>
using namespace std;


class FenWickTree{
	
	public:
	
	int get_next(int index){
		/*
			Algorithm: 
			1) Calculate 2's complement of index 
			2) And it with the index itself
			3) Add it with the index 
			4) return index
			
		 */	
		 index = index + (index & (-index));
		 return index;	
	}
	
	int get_parent(int index){
		
		/* 
			Algorithm: 
			1) Calculate 2's complement of index 
			2) And it with the index itself
			3) Subtract it with the index 
			4) return index
		
		*/
		
		index -= index & -(index);
		return index;
	}
	
	void display(int* bit, int len){
		for(int i=1; i<=len; i++ ){
			cout << bit[i] << " ";
		}
		cout << endl;
	}
	
	int* create(int arr[], int len){
		
		/* ALGORITHM:
			1) Create an aux array of N+1 size
			2) Fill it with zeroes from index 1 to N
			3) Loop an Update function that takes the tree, index, length, arr[i]
			3) Display the created bit adn return pointer to bit
		*/
		int* bit = new int[len+1];
		for(int i=1; i<=len; i++){
			bit[i] = 0; 
		}
		
		for(int i=0; i<len;i++){
			update(bit, i, len, arr[i]);
		}
		
		display(bit,len);
		return bit;
	}
	
	void update(int bit[], int index, int len,int val){
		index += 1;
		while(index <= len){
			bit[index] += val;
			index = get_next(index);
		}
	}
	
	void replace(int bit[], int arr[],int index, int len, int val ){
		val -= arr[index]; 
		update(bit,index,len,val);		
	}
	
	void delTree(int* &bit){
		delete[] bit;
		
	}
	
	int get_sum(int bit[], int index){
		
		index+=1;
		int sum = 0;
		while(index > 0){
			sum += bit[index];
			index = get_parent(index);
		}
		
		return sum;
	}
	
	int range_sum(int bit[], int start, int stop){
		int sum1 = get_sum(bit,start);
		int sum2 = get_sum(bit,stop);
		return sum2 - sum1;
	}
 
	
};


int main(){
 /*	int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    
    FenWickTree tree;
    int* bit = tree.create(freq, n);
    int res = tree.get_sum(bit,5);
    cout << res;
   */ 
    int arr[] = {8,4,9,2};
    int inv_count = tree.countInv(arr,4);
    cout << inv_count;
	
}
