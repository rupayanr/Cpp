#include<bits/stdc++.h>
#define vi vector<int> 
#define vvi vector<vector<int>> 

using namespace std;

void spiral(vvi &nums){
	
	// Define min row, max row, min col, max col (Corners of our wall)
	
	int minr=0, maxr=nums.size()-1, minc=0, maxc=nums[0].size()-1;
	
	int total = nums.size() * nums[0].size();
	int count = 0;
	 
	while(count < total ){
		// print left wall 
		for(int i=minr, j=minc; i<=maxr && count < total; i++){
			cout << nums[i][j] << endl;
			count++;
		}
		minc++;
		
		// bottom wall 
		for(int j=minc, i=maxr; j<=maxc && count < total; j++){
			cout << nums[i][j] << endl;
			count++;
		}
		maxr--;
		
		// right wall 
		for(int i=maxr, j=maxc; i>=minr && count < total; i-- ){
			cout << nums[i][j] << endl;
			count++;
		}
		maxc--;
		
		// top wall 
		for(int j=maxc, i=minr; j>=minc && count < total; j--){
			cout << nums[i][j] << endl;
			count++;
		}
		
		minr++;
		
	}
	
	
}

int main(){
	
	int n,m;
	cin >> n >> m;
	
	vvi nums(n,vi(m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> nums[i][j];
		}
	}
	
	spiral(nums);
}
