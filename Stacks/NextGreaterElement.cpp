#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

void findNextGreaterElement(vi &nums){
	// 2 5 9 3 1 12 6 8 7
	
	int n = nums.size(); // 9 
	vi res(n,0); // 
	stack<int> stk; 
	
	// Pushing the last element to the stack 
	stk.push(nums[n-1]);
	
	res[n-1] = -1; // [ -1] 
	
	// Now we check if the next elements are larger than the top most element or not
	for(int i = n-2; i>=0; i--){
	
	
		while(stk.size() > 0 && nums[i] >= stk.top()){
			
			stk.pop(); 
		}
		
		if(stk.size() == 0){
			
			res[i] = -1;
			
		}
		else{
		
			res[i] = stk.top();
			
		}
		
		stk.push(nums[i]);
		//cout << "Pushing into stack: " << nums[i] <<endl;
		//stk.push(nums[i]);
					
	}
	
	
	for(int i=0; i<n; i++){
		cout << res[i] << endl;
	}
	

}

int main(){
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	    freopen("error.txt", "w", stderr);
	#endif
	
	int n; 
	cin >> n; 
	
	vi nums(n);
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
	findNextGreaterElement(nums);
	
}
