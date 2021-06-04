#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mostFreqInt(int arr[], int len){

	map<int,int> m;
	int max_f = 0;
	int max_i = 0;
	
	// Creating a map of all array values incrementing their values acc. to freq
	for(int i=0; i < len; i++){
		m[arr[i]]++;
	}

	for(int i=0; i < len; i++){
		if(m[arr[i]] > max_f){
			max_f = m[arr[i]];
			max_i = i;
		}

		if(m[arr[i]] == max_f && arr[i] < arr[max_i]){
			max_i = i;
		}
	}

	cout << arr[max_i] << endl;

}


int main() {
	int len;
	cin >> len;
	int arr[len];
	

	for(int i=0; i < len; i++){
		cin >> arr[i];
	}

	mostFreqInt(arr,len);
		
}
