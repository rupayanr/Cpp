 #include <bits/stdc++.h>
 using namespace std;
 
 class Solution{
 	
 	public:
 	
	 vector<int> twoSum(vector<int> &nums, int target){
	 	vector<int> res;
	 	unordered_map<int,int> hash;
	 	for(int i=0; i<nums.size(); i++){
	 		if(hash.find(target - nums[i]) != hash.end()){
	 			int val = hash[target-nums[i]];
				res.push_back(val);
	 			res.push_back(i);
			 };
	 		hash[nums[i]] = i;
		 }
		 
		 return res;
	 }
 };
 
 
 int main(){
 	vector<int> vec = {2,7,9,11,15};
 	
 	Solution sol;
 	vector<int> ans = sol.twoSum(vec,26);
 	
 	for(auto a: ans){
 		cout << a << " ";
	}
 }
