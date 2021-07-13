#include<bits/stdc++.h>
using namespace std;


void display(vector<vector<int>> &nums){
	for(auto vec: nums){
		for(auto el: vec){
			cout << el << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void display(vector<int>vec){
	for(auto el: vec){
		cout << el << " ";
	}
	cout << endl;
}

vector<vector<int>> fourSum(int target, vector<int> &nums){
	
	
	vector<vector<int>> final;
	sort(nums.begin(),nums.end());
	int n = nums.size();

	
	if(nums.empty()){
		return final;
	}
	
	
	for(int i=0; i<n; i++){
		
		for(int j=i+1; j<n; j++){
			
			int target_2 = target - nums[j] - nums[i];
			int front = j+1;
			int back = n-1;
			
			while(front < back){
				
				int twosum = nums[front] + nums[back];
				if(twosum < target_2){
					front++;
				}
				else if(twosum > target_2){
					back--;
				}
				else{
					
					vector<int> res = {nums[i], nums[j], nums[front], nums[back]};
					final.push_back(res);

					
					while(front < back && nums[front] == res[2]) ++front;
					
					while(back > front && nums[back] == res[3]) --back;

				}
				
			}
			while(j+1 < n && nums[j+1] == nums[j]) ++j;	
		}
		while(i+1 < n && nums[i+1] == nums[i]) ++i;
	}
	
	display(final);
	
	return final;
	
	
}


int main(){
	
	vector<int> nums = {1,0,-1,0,-2,2};
	int target = 0;
	
	fourSum(target, nums);
	
}
