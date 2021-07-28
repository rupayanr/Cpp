#include <bits/stdc++.h>
using namespace std;
// Modify this problem using long long 
int _gridTraveller(int m, int n, map<pair<int,int>, int> &umap){
	
	if(umap.find({m,n}) != umap.end()){
		return umap[{m,n}];
	}
	
	if(m == 1 && n==1){
		return 1;
	}
	
	if(m == 0 || n==0){
		return 0;
	}
	
	
	return umap[{m,n}] = _gridTraveller(m-1,n,umap) + _gridTraveller(m,n-1,umap);
	
}

int gridTraveller(int m, int n){
	
	map<pair<int,int>, int> umap;
	return _gridTraveller(m,n,umap);
	
}


int main(){
	
	int ans = gridTraveller(10,10);
	cout << ans;
	
}
