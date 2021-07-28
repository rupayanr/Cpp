#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define f(o,n) for(int i=0; i<n; i++) 

using namespace std;

void display(vvi &nums){
	for(auto vec: nums){
		for(auto el: vec){
			cout << el << " ";
		}
		cout << endl;
	}
	cout << endl;
}


vvi threeSum(vi &nums){
	
	vvi final;
	
	int n = nums.size();
	// You need to sort the vector first only then the below logic will work 
	sort(nums.begin(),nums.end());
	
	f(o,n){
		int target = -nums[i];
		int front = i+1;
		int back = n-1;
		
		while(front < back){
		
			int sum = nums[front] + nums[back];
			
			if(sum < target){
				front++; 
			}
			else if(sum > target){
				back--;
			}
			else{
				
				vi triplet = {nums[i], nums[front], nums[back]};
				final.pb(triplet);
				while(front < back && nums[front] == triplet[1]){
					front++;
				}			
				
				while(back > front && nums[back] == triplet[2]){
					back--;
				}
	
			}
			
			while(i+1<n && nums[i+1] == nums[i]){
				i++;
			}
		}
	}
	
	
	return final;
	
}

int main(){
	vi nums = {-1, 0,1, 2, -1, -4};
	vvi res = threeSum(nums);
	display(res);
}
