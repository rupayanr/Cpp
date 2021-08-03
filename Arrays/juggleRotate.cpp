#include<bits/stdc++.h>
using namespace std;

/* 	left Rotation 		k=3
	{ 1 2 3 4 5 6 7 8 9 } -> { 4 5 6 7 8 9 1 2 3 } 
	  0 1 2 3 4 5 6 7 8 	   0 1 2 3 4 5 6 7 8
	
	size = 9; 
	
	ALGO
	1) Rotate in sets i 0 - gcd(n,k)
	2) Juggle from j (i - > d ) 
	
*/

void display(vector<int> nums){
	
	for(auto el: nums){
		cout << el << " ";
	}
	cout << endl;
}

int gcd(int a, int b){

	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a%b);
	}
}

void juggleRotate(vector<int> &a, int k){
	int n = a.size();
	
	// Running loop till gcd(n,k) { gives us max number of sets } 
	for(int i=0; i<gcd(n,k); i++){
		
		int j = i, temp = a[i];
		
		while(true){
			
			int d = (j+k) % n;
			
			if(d == i){
				break;
			}
				
			a[j] = a[d];
			j = d;	
		}
		
		a[j] = temp;
	}
	
}

int main(){
//	int ans = gcd(20,5);
//	cout << ans;
	
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	int k; 
	cin >> k;
	juggleRotate(nums,k);
	
	
	display(nums);
	
	
	

}
