#include <bits/stdc++.h>
using namespace std;



int main(){

	int n;
	vector<int> nums(n);
	cin >>n;
	for(int i=0; i<n;i++){
		cin >> nums[i];
	}
	
	int limit = (int)pow(2,n);
	
	for(int i=0; i<limit; i++){
		int temp = i;
		string s = " ";
		
		for(int j=n-1; j>=0; j--){
			int r = temp % 2;
			temp = temp /2;
			if(r == 0){
				s = "_\t" + s; 
			}
			else{
				s = to_string(nums[j]) +"\t" +s;
			}
		}
		
		cout << s << endl;
	}
	
}
