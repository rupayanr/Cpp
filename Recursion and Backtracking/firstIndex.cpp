#include<bits/stdc++.h>
using namespace std;

int firstIndex(int arr[], int idx, int x, int n){
	
	if(idx == n){
		return -1;
	}
	
	if (arr[idx] == x)
	{ 
		int next = firstIndex(arr,idx+1,x,n);
		if(next != -1){
			return next;
		}
		else{
			return idx;
		}
	}
	
	else{
		int res = firstIndex(arr,idx+1,x,n);
		return res;
	}
	
	

}



int main(){
	int n;
	cin >> n;
	
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	int d;
	cin >> d;
	
	int ans = firstIndex(arr,0,d,n);
	
	cout << ans << endl;
	
}

