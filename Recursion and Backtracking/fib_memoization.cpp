#include <bits/stdc++.h>

using namespace std;

int fib(int n, unordered_map<int,int> &memo){
	
	// Here we keep certain values in fib seq inside a hashmap and return their values instead of re calculating 
	// base case is when n <= 2 returns 1 since 1st 2 values are 1 in fib seq 
	// if n is in hashmap then return its value 
	// Store the values of recursion in the map itself and then return the map[n] value
	
	if(memo.find(n) != memo.end()){
		return memo[n];
	}
	
	if(n <= 2){
		return 1;
	}
	
	memo[n] = fib(n-1,memo) + fib(n-2,memo);
	return memo[n];
}

int fibRec(int n){
	
	// o(2^n) yeah do not ever use this 
	if( n<=2 ){
		return 1;
	}
	return fibRec(n-1) + fibRec(n-2);
}

int main(){
	
	unordered_map<int,int> memo;
	int ans = fib(40,memo);
	cout << ans;
	
}
