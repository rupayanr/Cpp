#include <bits/stdc++.h>
#define max 50000001
#define pb push_back
using namespace std;

bool arr[max];
vector<int> primes;

void sieve(){
	
	int n = max;
	arr[0] = arr[1] = true; // True is not Prime

	for(int i=2;i*i<n; i++){
		if(arr[i] == false){
			for(int j=i*i; j<n; j+=i){
				arr[j] = true;
			}
		}
	}
	
	for(int i=2;i<n;i++){
		if(!arr[i]){
			primes.pb(i);
		}
	}	

	
}

int main(){
	
	int t;
	cin >> t;
	sieve();
	while(t--){
		int k;
		cin >> k;
		
		cout << primes[k-1] << endl;
		
		
	}
}
