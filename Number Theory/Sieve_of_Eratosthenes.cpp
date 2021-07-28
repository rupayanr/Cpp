#include <bits/stdc++.h>
#define f(i,n) for(int i=2; i<n+1;i++)
#define fo(j,n) for(int j=i*i; j<n+1; j=j+i)
using namespace std;


// Alternative solution
void primeSieveAlt(int n){
	
	vector<int> primes(n+1,0);
	
	primes[0] = 1;
	primes[1] = 1;
	
	for(int i=2; i*i<=n; i++){
		if(primes[i] == 0){
			for(int j=2; j*i<=n; j++){
				primes[j*i] = 1;
			}
		}
	}
	
	f(i,n){
		if(primes[i] == 0){
			cout << i << " ";
		}
	}
	cout << endl;
	
}



void primeSieve(int n){
	
	//Create a dynamic array filled with zeroes
	
	// 0 is Prime 1 is NOT Prime
	
	vector<int> primes(n+1,0); // We assume that all are primes from 0 to n
	
	primes[0] = 1; // 0 and 1 are not prime
	primes[1] = 1;
	
	f(i,n){
		
		if(primes[i] == 0){
			fo(j,n){
				primes[j] = 1;
			}
		}
	}
	
	
	f(i,n){
		if(primes[i] == 0){
			cout << i << " ";
		}
	}
	cout << endl;
	
	
	
}


int main(){

	int n;
	cin >> n;
	
	primeSieve(n);
	primeSieveAlt(n);	
}
