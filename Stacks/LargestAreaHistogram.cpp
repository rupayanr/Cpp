#include <bits/stdc++.h>
#define vi vector<int> 
using namespace std;

/*
	We observe that fro aeach bar theres a left and right boudnary after which width cannot be 
	calculated. That boundary is the next smaller element for each bar on the right and left.

	If we maintain an array of theses NSE on right left we can use their diff - 1 to cal width
	using which we can find out the area  

	Algo for NSE:

	Left: 
	1) Push the first element in the stack with lb[0] = -1 (lower bound is -1)
	2) From i = 1,N start a loop 
		2.1) If the curr element is smaller than the top then we pop()
		2.2) If the stack turns empty i.e no smaller element was found so lb[i] = -1
		2.3) Else the lb[i] = stk.top() // the nse is found  

	Right:
	1) Same as left but upper bound becomes arr.len() lb[n-1] = arr.len()
	2) From N-2, 0 
	3) Same logic as left 

*/ 
void display(vi &nums){
	for(auto el : nums){
		cout << el << " ";
	}
	cout << endl;
}

void lah(vi &arr){

	// Getting the size of each  
	int n = arr.size();
	
	vi rb(n); // Right boundary array
	vi lb(n); // Left boundary array

	stack<int> stk; 

	// Fillng the right array 
	stk.push(n-1);
	rb[n-1] = n; // right boundary for the element is th earr length itself 

	for(int i = n-2; i>=0; i--){

		while(stk.size() > 0 && arr[i] <= arr[stk.top()]){
			// keep popping till you find that arr[stk.top()] is a smaller element 
			stk.pop();
		}

		if(stk.empty()){
			rb[i] = n; // upper bound 
		}
		else{
			rb[i] = stk.top();
		}

		stk.push(i);
	}


	while(stk.size() > 0){
		stk.pop();
	}


	stk.push(0);
	lb[0] = -1;
	// Filling the left boundary;

	for(int i=1; i<n; i++){
		
		while(stk.size() > 0 && arr[i] <= arr[stk.top()]){
			stk.pop();
		}

		if(stk.empty()){
			lb[i] = -1;
		}
		else{
			lb[i] = stk.top();
		}

		stk.push(i);

	}


	int area = INT_MIN;

	for(int i=0; i<n; i++){
		int width = rb[i] - lb[i] - 1; 
		area = max(area, arr[i] * width);
	}


	cout << area << endl;


}



int main(){

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	    freopen("error.txt", "w", stderr);
	#endif

	int n;
	cin >> n;

	vi arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	lah(arr);

}