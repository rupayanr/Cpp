#include<bits/stdc++.h>
#define vi vector<int> 

using namespace std;

void paintFence(int n, int k){
	
	int ii = 0; 
	int ij = k;
	int total = ij + ii;
	
	for(int i=1; i<n; i++){
		int nii = ij;
		int nij = total * (k-1);
		total = nii + nij;
		
		ii = nii;
		ij = nij;
	}
	
	cout << total << endl;
}

int main(){
	int n,k;
	cin >> n >> k; 
	paintFence(n,k);
}


