#include <bits/stdc++.h>
using namespace std;

/* Problem Statement 

	You are given an array of numbers and you have to return the subarrays whose sum = targetSum

	Intuition 
	- Through recursive memoization
	- First I will subtract the target sum with array elements 
	- Then run the program recursively till I reach a base case 
	- Base case is when target == 0 then I return an empty array 
	- Then you add the prev target sum i.e the element that got you zero 

*/

void display(list<int> lst){
	
	for(auto el: lst){
		cout << el << " ";
	}
	cout << endl;
}




list<int> _howSum(int sum, list<int> &lst, list<int> &res){
	
	if(sum == 0){
		return {0};
	}
	
	if(sum < 0){
		return {-1};
	}
	
	for(auto el: lst){
		
		// Foreach el in lst we subtract the sum 
		int rem = sum - el;
		res = _howSum(rem,lst,res);

		if(res.front() != -1 ){

			res.push_back(el);
		}
		
	}
	
	return res;
	
}

list<int> howSum(int sum, list<int> &lst){
	
	list<int> res= {};
	return _howSum(sum, lst, res);
	
}

//void howSum

int main(){
	
	list<int> lst = {4, 6, 2, 2};
	list<int> res = howSum(4,lst);
	display(lst);
	display(res); 
	
	
}
