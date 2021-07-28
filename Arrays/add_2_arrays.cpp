#include <bits/stdc++.h>
using namespace std;


int main(){
	int n1, n2;
	cin >> n1;
	
	int *a1 = new int[n1];
	for(int i=0; i<n1; i++){
		cin >> a1[i];
	}
	// 5 -> { 3 1 0 7 5}
  // 6 -> { 1 1 1 1 1 1}
	
	cin >> n2;
	int *a2 = new int[n2];
	
	for(int i=0; i<n2; i++){
		cin >> a2[i];
	}
	
	vector<int> vec;

	
	int ptr1 = n1 - 1;
	int ptr2 = n2 - 1;
	int carry = 0;

	
	while(ptr1 >= 0 || ptr2 >= 0 || carry ){
		int sum = 0;
		
		if(ptr1 >= 0){
			sum += a1[ptr1];
			ptr1--;
		}
		
		if(ptr2 >= 0){
			sum += a2[ptr2];
			ptr2--;
		}
		
		sum += carry;
		vec.push_back(sum % 10);
		carry = sum / 10;	
	}
	
	for(int i=vec.size()-1; i>=0; i--){
		cout << vec[i] << " ";
	}
}
