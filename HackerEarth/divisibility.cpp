#include <bits/stdc++.h>
using namespace std;

int main(){
	
	long n,x,odd=0,even=0,mid,rem=0,res=0;
	
	cin >> n;
	mid =n/2;
	vector<long> vec;
	
	for(long i=0;i<n;i++){
		cin >> x;
		vec.push_back(x);
	}
	
	for(long i=0;i<mid;i++){
		
		
		while(vec[i] > 0){
			rem = vec[i] % 10;
			vec[i] = vec[i] / 10;
		}
		
		if(i % 2 == 0){
			even += rem;
				
		}
		else{
			odd += rem;
			
		}
		
			
	}
	
	for(long i=mid; i< vec.size();i++){
		
		if(i % 2 == 0){
			even += vec[i] % 10;
		
		}
		else{
			odd += vec[i] % 10;
			
			
		}
	}
	

	
	if(abs(even - odd)% 11 == 0){
		cout << "OUI";
 	}
	else{
		cout << "NON";
	}
	
	
	


}

