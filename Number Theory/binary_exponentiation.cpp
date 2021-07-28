#include <bits/stdc++.h>
#define ll long long 
using namespace std;


ll binPower(int a, int n){
	/*
		ALGORITHM
		1,2 Same as recursive 
		3. while(n) // n>0
		  1. if(n%2) // odd power 
			a. res = res * a; n--;
		  2. a*=a ; n/=2;
		4. Return res
	*/	
	ll res = 1;
	if(n == 0){
		return 1;
	}
	
	while(n){
		if(n%2){
			res *= a;
		}
		
		a*=a;
		n/=2;
	
	}
	return res;
}

ll powerRec(int a, int n){
	//Recursive Method 
	/*ALGORITHM
	power(a,n) 
		1. If n == 0 return 1
		2. If n==1 return a // Not used later
		3. tmp = power(a,n/2)
		4. Res = tmp * tmp 
		5. if n is odd res * a
		6. Return res
	
	*/
	ll res = 1;
	if(n == 0){
		return 1;
	}

	
	ll tmp = powerRec(a,n/2);
	res = tmp * tmp;
	if(n % 2){
		res *= a;
	}
	
	return res;


}		

int main(){
	
	ll ans = binPower(2,5);
	cout << ans;
	
}
