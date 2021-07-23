#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
long long tree[N];
long long m; 
int n;


bool wood(int h){
	
	long long wood = 0;
	for(int i=0; i<n; i++){
		
		if(tree[i] > h){
			wood += tree[i] - h;
		}
	}

	
	return wood >= m;
}

int main(){
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		cin >> tree[i];
	}
	
	long long lo = 0;
	long long hi = *max_element(tree, tree+n);
	
	while(hi - lo>1){
	
		long long mid = hi+lo/2;
			
		if(wood(mid)){
			lo = mid;
		}
		else{
			hi = mid - 1;
		}
	}
	
	if(wood(hi)){
		cout << hi;
	}
	else{
		cout << lo;
	}
	
	
	
}
