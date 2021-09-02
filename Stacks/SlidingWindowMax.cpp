#include<bits/stdc++.h>
#define vi vector<int> 

using namespace std;

void swMax(vi &nums, int k){

	// First calculate the NGE for each element 
	// Then in each window see if the NGE(element) resides int the range if yes then jump to the NGE else don't
	// That pointer is your answer 
	int n = nums.size();
	stack<int> stk; 
	stk.push(n-1);
	
	vi nge(n);
	nge[n-1] = n; // upper bound 
	
	for(int i=n-2; i>=0; i--){

		while(stk.size() > 0 && nums[i] >= nums[stk.top()]){

			stk.pop();
		}

		if(stk.empty()){
			nge[i] = n;
		}
		else{
			nge[i] = stk.top();
		}

		stk.push(i);
	}

	// To find max in sliding window 

	// Run the loop till n-k because last window will be from i i+k and i+k = n
	for(int i=0; i<=n-k; i++){
		int j = i;
		while(nge[j] < i+k){
			j = nge[j];
		}

		cout << nums[j] << endl;
	}

}

int main(){

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	    freopen("error.txt", "w", stderr);
	#endif
	
	int n, k;
	cin >> n;

	vi nums(n);

	for(int i=0; i<n; i++){
		cin >> nums[i];
	}

	cin >> k;

	swMax(nums,k);
}