#include<bits/stdc++.h>
using namespace std;


bool isPrime(int n){
	for(int i=2; i*i<=n; i++){
		if(n % i == 0){
			return false;
		}
	}
	
	return true;
}

list<int> giveNotPrimes(list<int> nums){
	list<int> res;
	
	for(int val: nums){
		if(!isPrime(val)){
			res.push_back(val);
		}
	}
	
	return res;
}


int main(){
	int n;
	cin >> n;
	list<int> nums(n);
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		nums.push_back(x);
	}
	
	list<int> res = giveNotPrimes(nums);


	for(auto val:res){
		cout << val << ",";
	}

	cout << endl;
}
