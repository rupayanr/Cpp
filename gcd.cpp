#include <bits/stdc++.h>
#define pb push_back 
using namespace std;

void display(vector<int> vec){
	for(auto el: vec){
		cout << el << " ";
	}
	cout << endl;
}


int gcd_euclid(int a, int b){ // 10, 20 
	if(a > b){
		int temp = b;
		b = a;
		a = temp;
	}
	
	int rem = 1;
	while(rem != 0){
		rem = b % a;
		
		b = a;
		a = rem;
	}
	cout << b;
	return 1;
}

int gcd(int a, int b){
	// Naiive approach 
	// Find factors of a then use all the factors to divide b which ever is largest return that
	vector<int> fact;
	
	for(int i=1; i*i <= a; i++){
		if(a % i == 0){
			fact.pb(i);
			fact.pb(a/i);
		}
	}
	int max = 0;
	for(auto el: fact){
		
		if(b % el == 0){
			if(el >= max){
				max = el;
			}	
		}
	}
	
	display(fact);
	cout << max<<endl;
	return 1;
}

int main(){
	
		//gcd(1050,3580);
		
		gcd_euclid(1050,3580);
}
