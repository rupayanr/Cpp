#include<bits/stdc++.h>
using namespace std;



void barChart(vector<int> nums){
	int m = *max_element(nums.begin(), nums.end());
	int n = nums.size();
	

	vector<vector<char>> bar(m,vector<char>(n));
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			bar[i][j] = ' ';
		}	
	}
	

	
 	for(int i=0; i<n; i++){
		
		for(int j=m-1; j >= m - nums[i]; j--){
			
			bar[j][i] = '*';
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << bar[i][j] << " ";
		}
		cout << endl;
	}
	
}

int main(){
	
	int n;
	cin >> n;
	vector<int> nums(n);
	
	for(int i=0; i<n; i++){
	    cin >> nums[i];    
	}
	
	barChart(nums);
	
}
