#include<bits/stdc++.h>
#define vvi vector<vector<int>> 
#define vi vector<int> 

using namespace std; 

void findExit(vvi &nums){
	
	int dir = 0, i = 0, j = 0, n = nums.size(), m = nums[0].size(); 
	
	while((i>=0 && i<n) && (j>=0 && j<m)){
		
		dir = (dir + nums[i][j]) % 4;
		

		
		if(dir == 0) j++;
		else if(dir == 1) i++;
		else if(dir == 2) j--;
		else i--;
		
		
		cout << "Dir: "<<dir<<" ";
		cout << "Pos: " << i << " " << j << endl;
		
	}
	
	if(i < 0){
		i++;
	}
	
	if(j < 0){
		j++;
	}
	
	if(i >= n){
		i--;
	}
	
	if(j >= m){
		j--;
	}
	
	cout << i << endl;
	cout << j << endl;
	
	
	
} 

int main(){
	int n, m;
	cin >> n >> m;
	
	vvi nums(n,vi(m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> nums[i][j];
		}
	}
	
	findExit(nums); 
}
