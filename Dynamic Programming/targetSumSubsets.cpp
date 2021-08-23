#include<bits/stdc++.h>
#define vi vector<int> 
#define vb vector<bool>
#define vvb vector<vector<bool>>

using namespace std;

bool getSubsets(vi &nums, int target){
	int n = nums.size();
	
	vvb dp(n + 1, vb(target+1)); 
	
	for(int i=0; i<=n; i++){
		for(int j=0; j<=target; j++){
			
			// Base Cases 
			if(i == 0 && j == 0){
				dp[i][j] = true;
			}
			else if(j == 0){
				dp[i][j] = true;
			}
			else if(i == 0){
				dp[i][j] = false;
			}
			else{
				
				if(dp[i-1][j]){
					dp[i][j] = dp[i-1][j];
				}
				else{
					if(j >= nums[i]){
						dp[i][j] = dp[i-1][j - nums[i]];
					}
				}
				
				
			}
			
			
		}
	}
	return dp[n][target];
}


int main(){
	
int n;
cin >> n;
vi nums(n);

for(int i=0; i<n; i++){
	cin >> nums[i];
}
int target;
cin >> target;
if(getSubsets(nums,target)){
	cout << "true" << endl;
}
else{
	cout << "false" << endl;
	}
}

