#include<bits/stdc++.h>
#define vvi vector<vector<int>> 
#define vi vector<int> 

using namespace std;

void display(vvi nums){
	for(auto vec: nums){
		for(auto el: vec){
			cout << el << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void reverse(vvi &nums, int &n, int &m){
	
	for(int i=0; i<n; i++){
		int left=0, right=m-1;
		while(left < right){
			
			int temp = nums[i][left];
			nums[i][left] = nums[i][right];
			nums[i][right] = temp;
			left++;
			right--;
		}
	}
	cout << endl;
}

void transpose(vvi &a){
	
	int n = a.size();
	int m = a[0].size();
	int j = 0, i=0; 
	
	for(int i=0; i<n; i++){
		for(int j=i; j<m; j++){
			int temp = a[j][i];
			a[j][i] = a[i][j];
			a[i][j] = temp;		
		}
	}

}

int main(){
	
	
	int n,m;
	cin >> n >> m;
	
	vvi nums(n, vi(m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			
			cin >> nums[i][j];
		}
	}
	
	
	transpose(nums);
	reverse(nums,n,m);
	display(nums);
}
