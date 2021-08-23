#include<bits/stdc++.h>
#define vi vector<int> 
#define vvi vector<vector<int>> 
using namespace std; 

/*
	Problem: 
	Given length N print the no. of binary strings with no consecutive 0's in them 
	
	Solution: _ _ _ _  Say you are given 4 as i/p and then total no. of binary strings will be 2^4 
	But given restriction says no consecutive 0's 
		  0 1    2         3 					4 
	0	[ 0 1(0) 1(10)     Consider only 1's     		This stores the no. of binary str that satisfy the above condition for len 3 having no consecutive 0's and that end with 0  
	1	[ 0 1(1) 2(01,11)  Consider only 0's			Same as above but it ends with 1 

	Either make a 2D dp array but that takes O(2*n) space 
	Use 4 variables instead 
*/ 


void countBinaryStrings(int n){
	
	// Trivial cases when str len is 1 
	int old0 = 1; 
	int old1 = 1; 
	
	// Running a loop from 2 to n
	for(int i=2; i<=n; i++){
		int n0 = old1; 
		int n1 = old0 + old1; 
		
		old1 = n1; 
		old0 = n0; 
	}
	
	cout << old1 + old0 << endl;
	
	
}

int main(){
	int n; 
 	cin >> n; 
 	countBinaryStrings(n);
}
