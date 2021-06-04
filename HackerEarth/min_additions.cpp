/* Problem Statement :- Find out the min number of elements to be added in vector so that the floor(avg(sum/num)) <= k  */

#include <bits/stdc++.h>
#include <algorithm>
#define ll long long 
using namespace std;

int main(){
	
	ll t,n,k,x,sum,res,p;

	cin>>t;
			
	while(t--){
		cin>>n;
		cin>>k;
		
		for(int i=0; i<n;i++){
			
			cin >> x;
			sum += x;
		}
		
		p = sum/(k+1);
		p++;
		
		res = max(0LL,p-n);
	
		cout << res<< endl;
	}
}
