#include <bits/stdc++.h>
using namespace std;

void primeFactorSieve(int n){
	
		//Algorithm 
		/*First initialize an array of smallest prime factors with 0 till 100 
			
			1. Each number is there own smallest prime factor spf[i] = i
 			2. Start another loop from i*i and change spf[j] = i, Now we have actual smallest prime factors of each num till 100 
 			3. While(nmber != 1) we keep dividing the number by spf[number] n= n/spf[n]
	
		*/
		
		vector<int> spf(n+1,0);
		spf[0] = spf[1] = 1;
		
		for(int i=2; i<=n; i++){
			if(spf[i] == 0){
				 
				for(int j=i*i; j<=n; j+=i){
					
					spf[j] = i;
				}
			}
		}
			
	
		while(n!=1 && spf[n] !=0){
			cout << spf[n] << " ";
			n=n/spf[n];
			
		}
		
	
}


void primeFactors(int n){
	
	pair<int,int> pFact;
	
	for(int i=2; i*i<=n; i++){    //i = 3 n = 9 
		
		if(n % i == 0){		//9%3 == 0
			int count = 0;
			while(n % i == 0){  
				n = n/i;    // n = 9/3 = 3
				count++;
			}
			pFact = make_pair(i,count);
			cout << "("<<pFact.first << " ," << pFact.second << ")" << " ";
		
		}
		
	}
	
	if(n!= 1){
		pFact = make_pair(n,1);
		cout << "("<<pFact.first << " ," << pFact.second << ")";
	}
	
	
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		primeFactors(n);
		//primeFactorSieve(n);
	}
	
}
